/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"

void calculate_pc_sti(unsigned char opcode, struct player *player)
{
    if (opcode == 0x54)
        player->pc += 5;
    if (opcode == 0x68 || opcode == 0x78)
        player->pc += 7;
    if (opcode == 0x74 || 0x64 == opcode)
        player->pc += 6;
}

unsigned char arg_treg(struct player *player, int pos)
{
    unsigned char reg = player->instructions[pos];
    unsigned char reg_value = player->reg[reg];

    return reg_value;
}

void write_in_arena(corewar_t *corewar, struct player *player,
    unsigned char adress, unsigned char reg_value)
{
    corewar->arena[adress] = reg_value;
    print("Player %d(%s): copied[%d] in the adress [%i] in the arena\n",
        player->id, player->name, reg_value, adress);
}

static unsigned char get_second(struct player *player)
{
    unsigned char arg_3 = 0;

    if (player->types[1] == T_REG)
        arg_3 = player->instructions[player->pc + 5];
    else
        arg_3 = player->instructions[player->pc + 6];
    return arg_3;
}

void get_instructions(corewar_t *corewar, struct player *player,
    unsigned char reg, unsigned char reg_value)
{
    unsigned char ag_2 = 0;
    unsigned char arg_3 = 0;
    unsigned char adress = 0;

    if (player->types[1] == T_REG)
        ag_2 = arg_treg(player, player->pc + 2);
    else
        ag_2 = player->instructions[player->pc + 3];
    if (player->types[2] == T_REG) {
        if (player->types[1] == T_REG)
            arg_3 = arg_treg(player, player->pc + 3);
        else
            arg_3 = arg_treg(player, player->pc + 4);
    } else {
        arg_3 = get_second(player);
    }
    if ((player->pc + (ag_2 + arg_3) % IDX_MOD) > MEM_SIZE)
        player->pc = 0;
    adress = player->pc + (ag_2 + arg_3) % IDX_MOD;
    write_in_arena(corewar, player, adress, reg_value);
}

int sti(corewar_t *corewar, struct player *player)
{
    unsigned char option = player->instructions[player->pc + 1];
    char *binary = hex_byte(player, option);
    unsigned char reg = player->instructions[player->pc + 2];
    unsigned char reg_value = player->reg[reg];

    restart_type(player);
    find_type(player, binary);
    get_instructions(corewar, player, reg, reg_value);
    calculate_pc_sti(option, player);
    return 2;
}
