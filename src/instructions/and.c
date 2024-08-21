/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"

static void fill_types(struct player *current, char *binary)
{
    char **array = malloc(sizeof(char *) * 4);

    array[0] = my_strndup(binary, 2);
    array[1] = my_strndup(binary + 2, 2);
    array[2] = my_strndup(binary + 4, 2);
    array[3] = NULL;
    for (int i = 0; array[i] != NULL; i++) {
        if (strcmp_my(array[i], "01") == 1)
            current->types[i] = T_REG;
        if (strcmp_my(array[i], "10") == 1)
            current->types[i] = T_IND;
        if (strcmp_my(array[i], "11") == 1)
            current->types[i] = T_DIR;
    }
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    return;
}

static int and_result(struct player *player, corewar_t *corewar)
{
    int pc = player->pc + 2;
    int i = 0;
    int a = 0;
    int b = 0;

    for (; i < player->types[0]; i++)
        a = (a << 8) | corewar->arena[pc + i];
    pc += i;
    i = 0;
    for (; i < player->types[1]; i++)
        b = (b << 8) | corewar->arena[pc + i];
    pc += i;
    player->reg[(unsigned char)corewar->arena[pc]] = a & b;
    player->pc = pc + 1;
    player->inst_pos = pc + 1;
    if ((a & b) == 0)
        return 0;
    return 1;
}

int and_cmd(corewar_t *corewar, struct player *player)
{
    unsigned char option = corewar->arena[player->pc + 1];
    char *binary = hex_byte(player, option);

    restart_type(player);
    fill_types(player, binary);
    if (and_result(player, corewar) == 0)
        return 0;
    return 1;
}
