/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"


static void type_register(corewar_t *corewar, struct player *player, int c,
    int pc)
{
    int ldi = 0;
    int s = 0;

    for (int i = 0; i < 4; i++)
        ldi = (ldi << 8) | corewar->arena[player->pc + c % IDX_MOD + i];
    s = ldi + corewar->arena[pc + 1];
    player->reg[(unsigned char)corewar->arena[pc + 2]] = s;
    player->pc += 2;
    player->inst_pos = player->pc;
}

static void type_direct(corewar_t *corewar, struct player *player, int c,
    int pc)
{
    int ldi = 0;
    int s = 0;

    for (int i = 0; i < 4; i++)
        ldi = (ldi << 8) | corewar->arena[player->pc + c % IDX_MOD + i];
    for (int i = 0; i < 2; i++)
        s = (s << 8) | (ldi + corewar->arena[pc + 1 + i]);
    player->reg[(unsigned char)corewar->arena[pc + 3]] = s;
    player->pc += 3;
    player->inst_pos = player->pc;
}

static int ldi_register(corewar_t *corewar, struct player *player)
{
    int c = corewar->arena[player->pc + 2];
    int pc = player->pc + 2;

    if (player->types[1] == T_REG)
        type_register(corewar, player, c, pc);
    if (player->types[1] == T_DIR)
        type_direct(corewar, player, c, pc);
    if (player->types[1] == T_IND)
        return 0;
    player->pc += 1;
    player->inst_pos = player->pc;
    if (c == 0)
        return 0;
    return 1;
}

static int ldi_direct_indirect(corewar_t *corewar, struct player *player)
{
    int c = 0;
    int pc = player->pc + 3;

    for (int i = 0; i < 2; i++)
        c = (c << 8) | corewar->arena[pc + i];
    if (player->types[1] == T_REG)
        type_register(corewar, player, c, pc);
    if (player->types[1] == T_DIR)
        type_direct(corewar, player, c, pc);
    if (player->types[1] == T_IND)
        return 0;
    player->pc += 2;
    player->inst_pos = player->pc;
    if (c == 0)
        return 0;
    return 1;
}

int ldi(corewar_t *corewar, struct player *player)
{
    unsigned char option = corewar->arena[player->pc + 1];
    char *binary = hex_byte(player, option);

    restart_type(player);
    find_type(player, binary);
    if (player->types[0] == T_REG) {
        if (ldi_register(corewar, player) == 0)
            return 0;
    }
    if (player->types[0] == T_DIR || player->types[0] == T_IND) {
        if (ldi_direct_indirect(corewar, player) == 0)
            return 0;
    }
    player->pc += 2;
    player->inst_pos = player->pc;
    return 1;
}
