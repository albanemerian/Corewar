/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"

int aff(corewar_t *corewar, struct player *player)
{
    char value = (char)player->reg[(unsigned char)
        player->instructions[player->pc + 2]];

    print("Player %d(%s): REG[%d] contains character '%c'\n", player->id,
        player->name, player->instructions[player->pc + 2], value);
    player->pc += 3;
    return 2;
}
