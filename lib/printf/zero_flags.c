/*
** EPITECH PROJECT, 2023
** zero_flags
** File description:
** Some function for space flag
*/

#include "struct.h"
#include "my.h"

int my_put_zero(character_t *letter, char *nb, int j)
{
    for (int i = 0; i < letter->zero - my_strlen(nb) - letter->add - j; i++)
        my_putchar('0');
    my_putstr(nb);
    return (letter->zero);
}

int my_put_nbzero(character_t *letter, int nb, int neg)
{
    if (letter->add == 1 && neg == 0) {
        if (letter->dock > 0)
            letter->add = 0;
        my_putchar('+');
    }
    if (neg > 0) {
        my_putchar('-');
        my_put_nbr(nb);
        return (my_intlen(nb) + 1);
    }
    for (int i = 0; i < letter->zero - my_intlen(nb) - letter->add - neg; i++)
        my_putchar('0');
    my_put_nbr(nb);
    return (letter->zero + letter->add);
}

int my_put_unzero(character_t *letter, unsigned int nb)
{
    for (int i = 0; i < letter->zero - my_unsignedlen(nb); i++)
        my_putchar('0');
    my_put_unsigned(nb);
    return (letter->zero);
}

int my_put_longzero(character_t *letter, long nb, int neg)
{
    if (letter->add == 1 && neg == 0) {
        if (letter->dock > 0)
            letter->add = 0;
        my_putchar('+');
    }
    if (neg > 0) {
        my_putchar('-');
        my_put_long(nb);
        return (my_longlen(nb) + 1);
    }
    for (int i = 0; i < letter->zero - my_longlen(nb) - letter->add - neg; i++)
        my_putchar('0');
    my_put_long(nb);
    return (letter->zero + letter->add);
}
