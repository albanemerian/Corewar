/*
** EPITECH PROJECT, 2023
** printf header
** File description:
** head
*/

#include <stdarg.h>
#include "struct.h"

#pragma once

int fill_zero(const char *str, int i, character_t *letter);
int fill_dock(const char *str, int i, character_t *letter);

int my_character(va_list list, character_t *letter);
int my_percent(va_list list, character_t *letter);
int my_string(va_list list, character_t *letter);
int my_number(va_list list, character_t *letter);
int my_unsigned(va_list list, character_t *letter);
int my_octal(va_list list, character_t *letter);
int my_hexa1(va_list list, character_t *letter);
int my_hexa2(va_list list, character_t *letter);
int my_pointer(va_list list, character_t *letter);
int my_float(va_list list, character_t *letter);
int my_exp(va_list list, character_t *letter);
int my_exp2(va_list list, character_t *letter);
int my_choose(va_list list, character_t *letter);

int my_put_charspace(character_t *letter, char c);
int my_put_space(character_t *letter, char *nb);
int my_put_nbspace(character_t *letter, int nb, int neg);
int my_put_unspace(character_t *letter, unsigned int nb);
int my_put_longspace(character_t *letter, long nb, int neg);

char *my_put_ohash(char *nb);
char *my_put_oxhash(char *nb);
char *my_put_oxhash2(char *nb);

int my_put_zero(character_t *letter, char *nb, int j);
int my_put_nbzero(character_t *letter, int nb, int neg);
int my_put_unzero(character_t *letter, unsigned int nb);
int my_put_longzero(character_t *letter, long nb, int neg);

int my_printf(const char *format, ...);
