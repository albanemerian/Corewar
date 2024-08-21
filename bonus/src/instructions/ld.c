/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"

static int stock_reg_size(corewar_t *corewar, struct player *player, int ld)
{
    int c = 0;

    for (int i = 0; i < 4; i++)
        c = (c << 8) | corewar->arena[player->pc + ld % IDX_MOD + i];
    return c;
}

static int ld_indirect(corewar_t *corewar, struct player *player)
{
    int ld = 0;
    int c = 0;

    if (player->instructions[player->pc + 4] > 15)
        return 0;
    for (int i = 0; i < 2; i++)
        ld = (ld << 8) | player->instructions[player->pc + 2 + i];
    c = stock_reg_size(corewar, player, ld);
    player->reg[(unsigned char)player->instructions[player->pc + 4]] = c;
    print("Player %d(%s): REG[%d] contains %d\n", player->id, player->name,
        player->instructions[player->pc + 4], c);
    return 1;
}

static int ld_direct(corewar_t *corewar, struct player *player)
{
    unsigned char ld = 0;
    int c = 0;

    if (player->instructions[player->pc + 6] > 15)
        return 0;
    for (int i = 0; i < 4; i++)
        ld = (ld << 8) | player->instructions[player->pc + 2 + i];
    c = stock_reg_size(corewar, player, ld);
    player->reg[(unsigned char)player->instructions[player->pc + 6]] = c;
    print("Player %d(%s): REG[%d] contains %d\n", player->id, player->name,
        (unsigned char)player->instructions[player->pc + 6], c);
    return 1;
}

int ld_cmd(corewar_t *corewar, struct player *player)
{
    unsigned char option = player->instructions[player->pc + 1];
    char *binary = hex_byte(player, option);

    restart_type(player);
    find_type(player, binary);
    if (player->types[0] == T_IND)
        if (ld_indirect(corewar, player) == 0)
            return 0;
    if (player->types[0] == T_DIR)
        if (ld_direct(corewar, player) == 0)
            return 0;
    calculate_pc(player);
    return 1;
}
