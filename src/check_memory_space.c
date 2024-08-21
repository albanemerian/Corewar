/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** check_memory_space
*/

#include "corewar.h"

static bool check_memory_space(corewar_t *corewar, struct player *current,
    int adress, int size)
{
    for (int j = 0; j < current->size; j++) {
        if (corewar->arena[adress] != current->instructions[j])
            size++;
        adress++;
    }
    if (size == current->size)
        return false;
    return true;
}

bool check_memory(corewar_t *corewar)
{
    struct player *current = corewar->player;
    int adress = 0;
    int size = 0;

    for (int i = 0; i < corewar->nb_player; i++) {
        adress = current->adress;
        if (check_memory_space(corewar, current, adress, size) == false)
            return false;
        size = 0;
        current = current->next;
    }
    return true;
}
