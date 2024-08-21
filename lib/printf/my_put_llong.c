/*
** EPITECH PROJECT, 2023
** my_put_long
** File description:
** Display a long
*/

#include "my.h"

int my_put_llong(long long nb)
{
    long long n = nb;

    if (nb < 0) {
        my_putchar('-');
        n *= -1;
    }
    if (n / 10 != 0)
        my_put_llong(n / 10);
    if (n % 10 >= 0) {
        my_putchar(n % 10 + '0');
        return (0);
    }
    return (0);
}
