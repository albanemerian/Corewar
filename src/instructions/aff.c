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
        corewar->arena[player->pc + 2]];

    print("%c\n", value);
    player->pc += 3;
    player->inst_pos += 3;
    return 2;
}
