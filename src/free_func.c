/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** free_func
*/

#include "corewar.h"

void free_func(corewar_t *corewar)
{
    if (corewar->dump != NULL)
        free(corewar->dump);
    if (corewar->adresse != NULL)
        free(corewar->adresse);
    if (corewar->id != NULL)
        free(corewar->id);
    if (corewar != NULL)
        free(corewar);
}
