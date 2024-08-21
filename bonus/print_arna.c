/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** print_arna
*/

#include "corewar.h"

void print_arena(unsigned char arena[MEM_SIZE], int size)
{
    for (int i = 0; i < size; i++) {
        if (arena[i] == 0) {
            printf("%d", arena[i]);
        } else {
            printf("%x", arena[i]);
        }
    }
    printf("\n");
}

