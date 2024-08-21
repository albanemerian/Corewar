/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"

int zjmp(corewar_t *corewar, struct player *player)
{
    short jump = 0;
    unsigned int temp = player->pc + 1;

    if (player->carry == 1) {
        for (unsigned int i = temp; i < temp + 2; i++) {
            jump <<= 8;
            jump |= corewar->arena[i];
        }
        player->pc = player->pc + jump % IDX_MOD;
        return 2;
    }
    player->pc += 3;
    return 2;
}
