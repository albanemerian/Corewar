/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** get_dump
*/

#include "corewar.h"


int analyse_hexa(corewar_t *corewar, char *flag)
{
    char *dup = NULL;

    for (int i = 0; flag[i] != '\0'; i++) {
        if ((flag[i] < 48 || flag[i] > 57)) {
            write(2, "Invalid number of cycles\n", 26);
            return -1;
        }
    }
    dup = my_strdup(flag);
    corewar->nb_cycle = my_getnbr(dup);
    if (corewar->nb_cycle == -1)
        return 84;
    corewar->dump = my_strdup(flag);
    free(dup);
    return 0;
}
