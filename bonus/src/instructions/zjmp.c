/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"

int zjmp(corewar_t *corewar, struct player *player)
{
    unsigned char jump = 0;

    if (player->carry == 1) {
        jump = player->instructions[player->pc + 1] * 256 +
            player->instructions[player->pc + 2];
        player->pc = player->pc + jump % IDX_MOD;
        return 2;
    }
    player += 3;
    return 2;
}
