/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"

void st_reg(struct player *player, corewar_t *corewar)
{
    unsigned char reg = corewar->arena[player->pc + 2];
    unsigned char reg_value = player->reg[reg];
    unsigned char reg_dest = corewar->arena[player->pc + 3];

    player->reg[reg_dest] = reg_value;
}

void st_dir(struct player *player, corewar_t *corewar)
{
    unsigned char reg = corewar->arena[player->pc + 2];
    unsigned char reg_value = player->reg[reg];
    unsigned char dir = 0;

    if ((player->pc + corewar->arena[player->pc + 4]
        % IDX_MOD) > MEM_SIZE)
        player->pc = 0;
    dir = player->pc + corewar->arena[player->pc + 4] % IDX_MOD;
    corewar->arena[dir] = reg_value;
}

int st_cmd(corewar_t *corewar, struct player *player)
{
    unsigned char option = corewar->arena[player->pc + 1];
    char *binary = hex_byte(player, option);

    restart_type(player);
    find_type(player, binary);
    if (player->types[1] == T_REG)
        st_reg(player, corewar);
    else
        st_dir(player, corewar);
    calculate_pc(player);
    return 2;
}
    // print("reg %i reg value = %i\n", reg, reg_value);
