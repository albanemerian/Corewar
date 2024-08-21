/*
** EPITECH PROJECT, 2023
** exposant nb
** File description:
** exposant nb
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"
#include "printf.h"

int my_exp(va_list list, character_t *letter)
{
    return (my_put_exp(va_arg(list, double), letter->dock));
}

int my_exp2(va_list list, character_t *letter)
{
    return (my_put_exp2(va_arg(list, double), letter->dock));
}
