/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"

int sub(corewar_t *corewar, struct player *player)
{
    int a = player->reg[(int)player->instructions[player->pc + 2]];
    int b = player->reg[(int)player->instructions[player->pc + 3]];

    player->reg[(int)player->instructions[player->pc + 4]] = a - b;
    print("Player %d(%s): Difference between REG[%d] and REG[%d]",
        player->id, player->name,
        (unsigned char)player->instructions[player->pc + 2],
        (unsigned char)player->instructions[player->pc + 3]);
    print(" stock in REG[%d]\n",
        (unsigned char)player->instructions[player->pc + 4]);
    player->pc += 5;
    return 2;
}
