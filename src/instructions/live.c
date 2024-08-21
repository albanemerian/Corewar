/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"

int live(corewar_t *corewar, struct player *player)
{
    struct player *temp = corewar->player;

    while (temp != NULL) {
        temp->alive = false;
        temp = temp->next;
    }
    print("The player %d(%s) is alive.\n", player->id, player->name);
    player->alive = true;
    corewar->live_cycle += 1;
    player->pc += 5;
    player->inst_pos += 5;
    return 2;
}
