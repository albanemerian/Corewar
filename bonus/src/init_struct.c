/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** init_struct
*/

#include "corewar.h"

void init_struct(corewar_t *corewar)
{
    char **temp = NULL;
    int *temp2 = NULL;

    corewar->adresses = my_malloc(temp2, sizeof(int) * 1);
    corewar->ids = my_malloc(temp, sizeof(char *) * 1);
    corewar->nb_player = 0;
    corewar->num = 1;
    corewar->nb_cycle = 0;
    corewar->dump = NULL;
}
