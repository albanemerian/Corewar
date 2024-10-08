/*
** EPITECH PROJECT, 2023
** exposant.c
** File description:
** make exposant
*/

#include "my.h"

static int count_pos_nbr(double nb)
{
    int n = nb;
    int count = 0;

    while (n > 1) {
        count++;
        n = n / 10;
    }
    return (count - 1);
}

static int count_neg_nbr(double nb)
{
    int result = nb;
    int count = 0;
    int zero = 0;

    while (result == 0) {
        nb = nb * 10;
        result = nb;
        count++;
    }
    return (count);
}

static int neg_expo(double nb, int count_caractere)
{
    int reste = nb;
    signed long int part2;
    int count = count_neg_nbr(nb);
    int decnb = (long)(nb * my_compute_power_rec(10, (count)));
    char *str = "e-0";

    while (reste == 0) {
        nb *= 10;
        reste = nb;
    }
    my_put_nbr(decnb);
    my_putchar('.');
    reste = nb / 1;
    nb = (nb - reste) * 1000000;
    part2 = (signed long int)(nb + 0.5);
    my_put_nbr(part2);
    my_putstr(str);
    my_put_nbr(count);
    return (11 + count);
}

static int printnbf(double nb, double nbf, int reste)
{
    int count_caractere = 0;

    nbf = (nbf * 1000000000) + 0.5;
    nbf = nbf / 1000000000;
    for (int i = 0; i < 7; i++) {
        reste = nbf;
        nbf = nbf - reste;
        nbf *= 10;
        reste = nbf;
        my_put_nbr(nbf);
        count_caractere ++;
    }
    return (count_caractere);
}

static int pos_expo(double nb, int count_caractere)
{
    int reste = nb;
    signed long int part2;
    int count = count_pos_nbr(nb);
    int decnb = (long)(nb / my_compute_power_rec(10, (count)));
    int fin = (my_compute_power_rec(10, (count)));
    char *str = "e+0";
    double nbf = (nb / my_compute_power_rec(10, (count)));

    my_put_nbr(decnb);
    my_putchar('.');
    count_caractere += 2;
    count_caractere += printnbf(nb, nbf, reste);
    my_putstr(str);
    count_caractere += 3;
    my_put_nbr(count);
    count_caractere += count;
    return (count_caractere);
}

int my_put_exp(double nb)
{
    int exp = nb;
    int count_caractere = 0;

    if (nb < 0) {
        my_putchar('-');
        count_caractere++;
        nb = nb * (-1);
    }
    if (exp == 0) {
        count_caractere += neg_expo(nb, count_caractere);
    } else {
        count_caractere += pos_expo(nb, count_caractere);
    }
    return (12);
}
