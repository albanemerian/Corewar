/*
** EPITECH PROJECT, 2023
** space_flags
** File description:
** Some function for space flag
*/

#include "struct.h"
#include "my.h"

int my_put_charspace(character_t *letter, char c)
{
    for (int i = 0; i < letter->space - 1; i++)
        my_putchar(' ');
    my_putchar(c);
    return (letter->space);
}

int my_put_space(character_t *letter, char *nb)
{
    for (int i = 0; i < letter->space - my_strlen(nb); i++)
        my_putchar(' ');
    my_putstr(nb);
    return (letter->space);
}

int my_put_nbspace(character_t *letter, int nb, int neg)
{
    if (letter->neg == 1) {
        if (letter->add == 1 && neg == 0)
            my_putchar('+');
        if (neg > 0)
            my_putchar('-');
        my_put_nbr(nb);
        for (int i = 0; i < letter->space - my_intlen(nb) - neg -
            letter->add; i++)
            my_putchar(' ');
        return (letter->space + neg + my_intlen(nb));
    }
    for (int i = 0; i < letter->space - my_intlen(nb) - neg - letter->add; i++)
        my_putchar(' ');
    if (letter->add == 1 && neg == 0)
        my_putchar('+');
    if (neg > 0)
        my_putchar('-');
    my_put_nbr(nb);
    return (letter->space);
}

int my_put_unspace(character_t *letter, unsigned int nb)
{
    if (letter->neg == 1) {
        my_put_unsigned(nb);
        for (int i = 0; i < letter->space - my_unsignedlen(nb); i++)
            my_putchar(' ');
        return (letter->space + my_unsignedlen(nb));
    }
    for (int i = 0; i < letter->space - my_unsignedlen(nb); i++)
        my_putchar(' ');
    my_put_unsigned(nb);
    return (letter->space);
}

int my_put_longspace(character_t *letter, long nb, int neg)
{
    if (letter->neg == 1) {
        if (letter->add == 1 && neg == 0)
            my_putchar('+');
        if (neg > 0)
            my_putchar('-');
        my_put_long(nb);
        for (int i = 0; i < letter->space - my_longlen(nb) - neg -
            letter->add; i++)
            my_putchar(' ');
        return (letter->space + neg + my_longlen(nb));
    }
    for (int i = 0; i < letter->space - my_longlen(nb) - neg - letter->add;
        i++)
        my_putchar(' ');
    if (letter->add == 1 && neg == 0)
        my_putchar('+');
    if (neg > 0)
        my_putchar('-');
    my_put_long(nb);
    return (letter->space);
}
