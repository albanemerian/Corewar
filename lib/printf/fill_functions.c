/*
** EPITECH PROJECT, 2023
** fill_functions
** File description:
** Philippe
*/

#include "my.h"
#include "struct.h"

int fill_zero(const char *str, int i, character_t *letter)
{
    int x = 0;
    int j = i;

    while (str[i] >= '0' && str[i] <= '9') {
        i++;
        x++;
    }
    if (x > 0) {
        letter->zero = my_getnbr(&str[j]);
        return (my_intlen(letter->zero));
    }
    letter->zero = 1;
    return (my_intlen(letter->zero));
}

int fill_dock(const char *str, int i, character_t *letter)
{
    int x = 0;
    int j = i;

    while (str[i] >= '0' && str[i] <= '9') {
        i++;
        x++;
    }
    if (x > 0) {
        letter->dock = my_getnbr(&str[j]);
        letter->zero = letter->dock;
        return (my_intlen(letter->dock));
    }
    letter->dock = 1;
    letter->zero = letter->dock;
    return (my_intlen(letter->dock));
}
