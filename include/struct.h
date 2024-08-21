/*
** EPITECH PROJECT, 2023
** struct header
** File description:
** head
*/

#include <stdarg.h>

#pragma once

typedef struct character_s {
    int hashtag;
    int zero;
    int neg;
    int space;
    int add;
    int l;
    int dock;
} character_t;

typedef struct printf_s {
    char flags;
    int (*pf)(va_list, character_t *letter);
} printf_t;
