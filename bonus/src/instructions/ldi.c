/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"

static int load_in_arena(corewar_t *corewar, struct player *player, int s)
{
    int c = 0;

    for (int i = 0; i < 4; i++)
        c = (c << 8) | corewar->arena[player->pc + s % IDX_MOD + i];
    return c;
}

static void type_register(corewar_t *corewar, struct player *player, int c,
    int pc)
{
    int ldi = 0;
    int s = 0;
    int load = 0;

    for (int i = 0; i < 4; i++)
        ldi = (ldi << 8) | corewar->arena[player->pc + c % IDX_MOD + i];
    s = ldi + player->instructions[pc + 1];
    load = load_in_arena(corewar, player, s);
    player->reg[(unsigned char)player->instructions[pc + 2]] = load;
    print("Player %d(%s): REG[%d] contains %d\n", player->id, player->name,
        player->instructions[pc + 2], load);
    player->pc += 2;
}

static void type_direct(corewar_t *corewar, struct player *player, int c,
    int pc)
{
    int ldi = 0;
    int s = 0;
    int load = 0;

    for (int i = 0; i < 4; i++)
        ldi = (ldi << 8) | corewar->arena[player->pc + c % IDX_MOD + i];
    for (int i = 0; i < 2; i++)
        s = (s << 8) | (ldi + player->instructions[pc + 1 + i]);
    load = load_in_arena(corewar, player, s);
    player->reg[(unsigned char)player->instructions[pc + 3]] = load;
    print("Player %d(%s): REG[%d] contains %d\n", player->id, player->name,
        player->instructions[pc + 3], load);
    player->pc += 3;
}

static int ldi_register(corewar_t *corewar, struct player *player)
{
    int c = player->instructions[player->pc + 2];
    int pc = player->pc + 2;

    if (player->types[1] == T_REG)
        type_register(corewar, player, c, pc);
    if (player->types[1] == T_DIR)
        type_direct(corewar, player, c, pc);
    if (player->types[1] == T_IND)
        return 0;
    player->pc += 1;
    return 1;
}

static int ldi_direct_indirect(corewar_t *corewar, struct player *player)
{
    int c = 0;
    int pc = player->pc + 3;

    for (int i = 0; i < 2; i++)
        c = (c << 8) | player->instructions[pc + i];
    if (player->types[1] == T_REG)
        type_register(corewar, player, c, pc);
    if (player->types[1] == T_DIR)
        type_direct(corewar, player, c, pc);
    if (player->types[1] == T_IND)
        return 0;
    player->pc += 2;
    return 1;
}

int ldi(corewar_t *corewar, struct player *player)
{
    unsigned char option = player->instructions[player->pc + 1];
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
    return 1;
}
