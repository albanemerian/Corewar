/*
** EPITECH PROJECT, 2023
** pf_mini_printf
** File description:
** Pointer on function from Mini_Printf
*/

#include <stdarg.h>
#include "my.h"
#include "printf.h"

static void put_sign(character_t *letter, int neg)
{
    if (letter->add == 1 && neg == 0)
        my_putchar('+');
    if (neg > 0)
        my_putchar('-');
}

static int int_len_flag(va_list list, int nb, character_t *letter)
{
    int neg = 0;

    if (nb < 0) {
        nb *= -1;
        neg = 1;
    }
    if (letter->space > 0)
        return (my_put_nbspace(letter, nb, neg));
    if (letter->zero > 0) {
        if (nb < 0)
            my_putchar('-');
        return (my_put_nbzero(letter, nb, neg));
    }
    put_sign(letter, neg);
    my_put_nbr(nb);
    return (my_intlen(nb));
}

static int long_len_flag(va_list list, long nb, character_t *letter)
{
    int neg = 0;

    if (nb < 0) {
        nb *= -1;
        neg = 1;
    }
    if (letter->space > 0) {
        return (my_put_longspace(letter, nb, neg));
    }
    if (letter->zero > 0) {
        if (nb < 0)
            my_putchar('-');
        return (my_put_longzero(letter, nb, neg));
    }
    put_sign(letter, neg);
    my_put_long(nb);
    return (my_longlen(nb));
}

int my_character(va_list list, character_t *letter)
{
    char c = va_arg(list, int);

    if (letter->space > 0)
        return (my_put_charspace(letter, c));
    my_putchar(c);
    return (1);
}

int my_percent(va_list list, character_t *letter)
{
    if (letter->space > 0)
        return (my_put_charspace(letter, '%'));
    my_putchar('%');
    return (1);
}

int my_string(va_list list, character_t *letter)
{
    char *str = va_arg(list, char *);

    if (letter->space > 0)
        return (my_put_space(letter, str));
    my_putstr(str);
    return (my_strlen(str));
}

int my_number(va_list list, character_t *letter)
{
    int nb = 0;
    long nb_long = 0;

    if (letter->l == 1) {
        nb_long = va_arg(list, long);
        return (long_len_flag(list, nb_long, letter));
    } else {
        nb = va_arg(list, int);
        return (int_len_flag(list, nb, letter));
    }
}
