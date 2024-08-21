/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** Display a int
*/

#include "my.h"
#include <stdio.h>

int my_put_i(long int nb)
{
    long int n = (long)nb;
    int compteur = 0;

    if (n < 0) {
        my_putchar('-');
        compteur ++;
        n *= -1;
    }
    n = nb;
    if (n / 10 != 0)
        my_put_i(n / 10);
    if (n % 10 >= 0) {
        my_putchar(n % 10 + '0');
        compteur++;
        return (0);
    }
    return (0);
}
