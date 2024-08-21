/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Our version of Printf()
*/

#include <stdlib.h>
#include <stdarg.h>
#include "struct.h"
#include "printf.h"
#include "my.h"

const printf_t FLAGS_FUNCTION[] = {{'%', &my_percent},
    {'c', &my_character}, {'s', &my_string}, {'d', &my_number},
    {'i', &my_number}, {'u', &my_unsigned}, {'o', &my_octal},
    {'x', &my_hexa1}, {'X', &my_hexa2}, {'p', &my_pointer},
    {'f', &my_float}, {'F', &my_float}, {'e', &my_exp},
    {'E', &my_exp2}, {'g', &my_choose}};

static int reboot_flag_character(character_t *letter)
{
    letter->hashtag = 0;
    letter->zero = 0;
    letter->neg = 0;
    letter->space = 0;
    letter->add = 0;
    letter->l = 0;
    letter->dock = 0;
    return (0);
}

static int increase_i(char c, int j, character_t *letter)
{
    char *flags = "#+-";
    int result = 0;

    if (flags[j] == c && flags[j] == '#') {
        letter->hashtag = 1;
        result++;
    }
    if (flags[j] == c && flags[j] == '+') {
        letter->add = 1;
        result++;
    }
    if (flags[j] == c && flags[j] == '-') {
        letter->neg = 1;
        result++;
    }
    return (result);
}

static int set_flag_character(const char *str, int c, character_t *letter)
{
    int i = 0;
    char *flags = "#+-0.";

    for (int j = 0; flags[j] != '\0'; j++) {
        if (flags[j] == str[c + i] && flags[j] == '0') {
            i++;
            i += fill_zero(str, c + i, letter);
        }
        i += increase_i(str[c + i], j, letter);
    }
    if (str[c + i] >= '1' && str[c + i] <= '9') {
        letter->space = my_getnbr(&str[c + i]);
        i += my_intlen(letter->space);
    }
    if (str[c + i] == '.') {
        i++;
        i += fill_dock(str, c + i, letter);
    }
    return (i);
}

static int set_length(const char *str, int c, character_t *letter)
{
    if (str[c] == 'l' && str[c + 1] != 'l') {
        letter->l = 1;
        return (1);
    }
    return (0);
}

static int error_flag(int temp, const char *format, int i)
{
    if (temp == 0) {
        for (; format[i] != '%'; i--);
        my_putchar('%');
    }
    return (i);
}

static int error_flag2(int temp)
{
    if (temp > 0)
        return (temp);
    return (0);
}

static int disp_arg(char c, va_list list, character_t *letter)
{
    int result = 0;
    int temp = 0;

    for (int i = 0; FLAGS_FUNCTION[i].flags != '\0'; i++) {
        if (FLAGS_FUNCTION[i].flags == c) {
            result += FLAGS_FUNCTION[i].pf(list, letter);
            return (result);
        }
    }
    return (result);
}

static int up_my_i(int i, const char *format, character_t *letter)
{
    i++;
    i += set_flag_character(format, i, letter);
    i += set_length(format, i, letter);
    return (i);
}

int my_printf(const char *format, ...)
{
    va_list list;
    int result = 0;
    character_t letter = {0, 0, 0, 0, 0, 0, 0};
    int temp = 0;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        temp = reboot_flag_character(&letter);
        if (format[i + 1] != '\0' && format[i] == '%') {
            i = up_my_i(i, format, &letter);
            temp += disp_arg(format[i], list, &letter);
            i = error_flag(temp, format, i);
            result += temp;
        } else {
            my_putchar(format[i]);
            result++;
        }
    }
    va_end(list);
    return (result);
}
