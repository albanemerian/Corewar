/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"

int live(corewar_t *corewar, struct player *player)
{
    if (player->alive == true)
        print("The player %d(%s) is alive.\n", player->id, player->name);
    player->pc += 5;
    return 2;
}
