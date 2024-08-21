/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"


static int lld_indirect(corewar_t *corewar, struct player *player)
{
    int lld = 0;

    for (int i = 0; i < 2; i++)
        lld = (lld << 8) | corewar->arena[player->pc + 2 + i];
    player->reg[(unsigned char)corewar->arena[player->pc + 4]] = lld;
    if (corewar->arena[player->pc + 4] < 0 ||
        corewar->arena[player->pc + 4] > 16)
        return 0;
    return 1;
}

static int lld_direct(corewar_t *corewar, struct player *player)
{
    unsigned char lld = 0;

    for (int i = 0; i < 4; i++)
        lld = (lld << 8) | corewar->arena[player->pc + 2 + i];
    player->reg[(unsigned char)corewar->arena[player->pc + 6]] = lld;
        if (corewar->arena[player->pc + 6] < 0 ||
            corewar->arena[player->pc + 6] > 16)
        return 0;
    return 1;
}

int lld(corewar_t *corewar, struct player *player)
{
    unsigned char option = corewar->arena[player->pc + 1];
    char *binary = hex_byte(player, option);

    restart_type(player);
    find_type(player, binary);
    if (player->types[0] == T_IND) {
        if (lld_indirect(corewar, player) == 0) {
            calculate_pc(player);
            return 0;
        }
    }
    if (player->types[0] == T_DIR) {
        if (lld_direct(corewar, player) == 0) {
            calculate_pc(player);
            return 0;
        }
    }
    calculate_pc(player);
    return 1;
}
