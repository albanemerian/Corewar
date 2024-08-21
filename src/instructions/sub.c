/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"

int sub(corewar_t *corewar, struct player *player)
{
    int a = player->reg[(int)corewar->arena[player->pc + 2]];
    int b = player->reg[(int)corewar->arena[player->pc + 3]];

    player->reg[(int)corewar->arena[player->pc + 4]] = a - b;
    player->pc += 5;
    player->inst_pos = player->pc;
    if (corewar->arena[player->pc + 4] < 0 ||
        corewar->arena[player->pc + 4] > 16)
        return 0;
    return 1;
}
