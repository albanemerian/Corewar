/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"

int add(corewar_t *corewar, struct player *player)
{
    int a = player->reg[(unsigned char)player->instructions[player->pc + 2]];
    int b = player->reg[(unsigned char)player->instructions[player->pc + 3]];

    player->reg[(unsigned char)player->instructions[player->pc + 4]] = a + b;
    print("Player %d(%s): Sum of REG[%d] and REG[%d] stock in REG[%d]\n",
        player->id, player->name,
        (unsigned char)player->instructions[player->pc + 2],
        (unsigned char)player->instructions[player->pc + 3],
        (unsigned char)player->instructions[player->pc + 4]);
    player->pc += 5;
    return 2;
}
