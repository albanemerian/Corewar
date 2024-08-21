/*
** EPITECH PROJECT, 2023
** pf_my_printf
** File description:
** Pointer on function from MyPrintf
*/

#include <stdarg.h>
#include "my.h"
#include "printf.h"

static int float_zero(character_t *letter, double nb, int neg)
{
    if (letter->add == 1 && neg == 0)
        my_putchar('+');
    if (neg == 1)
        my_putchar('-');
    for (int i = 0; i < letter->zero - my_float_len(nb, letter->dock)
        - letter->add - neg; i++)
        my_putchar('0');
    my_put_float(nb, letter->dock);
    return (letter->zero + letter->add + neg);
}

static int float_spaces(double nb, character_t *letter, int neg)
{
    if (letter->neg == 1) {
        if (letter->add == 1 && neg == 0)
            my_putchar('+');
        if (neg == 1)
            my_putchar('-');
        my_put_float(nb, letter->dock);
        for (int i = 0; i < letter->space - my_float_len(nb, letter->dock) -
            letter->add - neg; i++)
            my_putchar(' ');
        return (letter->space + my_float_len(nb, letter->dock));
    }
    for (int i = 0; i < letter->space - my_float_len(nb, letter->dock) -
        letter->add - neg; i++)
        my_putchar(' ');
    if (letter->add == 1 && neg == 0)
        my_putchar('+');
    if (neg == 1)
        my_putchar('-');
    my_put_float(nb, letter->dock);
    return (letter->space + my_float_len(nb, letter->dock));
}

int my_float(va_list list, character_t *letter)
{
    double nb = va_arg(list, double);
    int neg = 0;

    if (nb < 0.00) {
        nb *= -1.00;
        neg++;
    }
    if (letter->dock == 0)
        letter->dock = 6;
    if (letter->space > 0)
        return (float_spaces(nb, letter, neg));
    if (letter->zero > 0)
        return (float_zero(letter, nb, neg));
    my_put_float(nb, letter->dock);
    return (my_float_len(nb, letter->dock));
}

int my_choose(va_list list, character_t *letter)
{
    return (my_put_g(va_arg(list, double)));
}
