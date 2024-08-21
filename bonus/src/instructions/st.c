/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"

void st_reg(struct player *player)
{
    unsigned char reg = player->instructions[player->pc + 2];
    unsigned char reg_value = player->reg[reg];
    unsigned char reg_dest = player->instructions[player->pc + 3];

    player->reg[reg_dest] = reg_value;
    print("Player %d(%s): REG[%d] contains %d\n", player->id, player->name,
        reg_dest, reg_value);
}

void st_dir(struct player *player, corewar_t *corewar)
{
    unsigned char reg = player->instructions[player->pc + 2];
    unsigned char reg_value = player->reg[reg];
    unsigned char dir = 0;

    if ((player->pc + player->instructions[player->pc + 4]
        % IDX_MOD) > MEM_SIZE)
        player->pc = 0;
    dir = player->pc + player->instructions[player->pc + 4] % IDX_MOD;
    corewar->arena[dir] = reg_value;
    print("Player %d(%s): copied[%d] in the adress [%i] in the arena\n",
        player->id, player->name, reg_value, dir);
}

int st_cmd(corewar_t *corewar, struct player *player)
{
    unsigned char option = player->instructions[player->pc + 1];
    char *binary = hex_byte(player, option);

    restart_type(player);
    find_type(player, binary);
    if (player->types[1] == T_REG)
        st_reg(player);
    else
        st_dir(player, corewar);
    calculate_pc(player);
    return 2;
}
