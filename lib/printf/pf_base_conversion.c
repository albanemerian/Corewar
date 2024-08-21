/*
** EPITECH PROJECT, 2023
** pf_my_printf
** File description:
** Pointer on function from MyPrintf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"
#include "printf.h"

int my_unsigned(va_list list, character_t *letter)
{
    unsigned int n = va_arg(list, unsigned int);

    if (letter->space > 0)
        return (my_put_unspace(letter, n));
    if (letter->zero > 0)
        return (my_put_unzero(letter, n));
    my_put_unsigned(n);
    return (my_unsignedlen(n));
}

int my_octal(va_list list, character_t *letter)
{
    unsigned int n = va_arg(list, unsigned int);
    char *nb = convert_base(my_itoa(n), "0123456789", "01234567");
    char *temp = my_strdup(nb);
    int i = 0;

    if (letter->hashtag == 1) {
        temp = my_put_ohash(nb);
        i = 1;
    }
    if (letter->space > 0)
        return (my_put_space(letter, temp));
    if (letter->zero > 0) {
        my_putchar('0');
        return (my_put_zero(letter, temp, i));
    }
    my_putstr(temp);
    return (my_strlen(temp));
}

int my_hexa1(va_list list, character_t *letter)
{
    unsigned int n = va_arg(list, unsigned int);
    char *nb = convert_base(my_itoa(n), "0123456789", "0123456789abcdef");
    char *temp = my_strdup(nb);
    int i = 0;

    if (letter->hashtag == 1) {
        temp = my_put_oxhash(nb);
        i = 2;
    }
    if (letter->space > 0)
        return (my_put_space(letter, temp));
    if (letter->zero > 0)
        return (my_put_zero(letter, nb, i));
    my_putstr(temp);
    return (my_strlen(temp));
}

int my_hexa2(va_list list, character_t *letter)
{
    unsigned int n = va_arg(list, unsigned int);
    char *nb = convert_base(my_itoa(n), "0123456789", "0123456789ABCDEF");
    char *temp = my_strdup(nb);
    int i = 0;

    if (letter->hashtag == 1) {
        temp = my_put_oxhash2(nb);
        i = 2;
    }
    if (letter->space > 0)
        return (my_put_space(letter, temp));
    if (letter->zero > 0) {
        my_putstr("0X");
        return (my_put_zero(letter, nb, i));
    }
    my_putstr(temp);
    return (my_strlen(temp));
}

int my_pointer(va_list list, character_t *letter)
{
    unsigned int n = va_arg(list, unsigned int);
    char *nb = convert_base(my_itoa(n), "0123456789", "0123456789abcdef");

    my_putstr("0x");
    my_putstr(nb);
    return (my_strlen(nb) + 2);
}
