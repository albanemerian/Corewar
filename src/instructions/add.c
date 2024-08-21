/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"

int add(corewar_t *corewar, struct player *player)
{
    int a = player->reg[(unsigned char)corewar->arena[player->pc + 2]];
    int b = player->reg[(unsigned char)corewar->arena[player->pc + 3]];

    player->reg[(unsigned char)corewar->arena[player->pc + 4]] = a + b;
    player->pc += 5;
    player->inst_pos += 5;
    if (a + b == 0)
        return 0;
    return 1;
}
