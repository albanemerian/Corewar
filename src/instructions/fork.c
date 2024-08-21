/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** live instruction
*/

#include "corewar.h"

void cp_reg(struct player *new_player, int reg[REG_NUMBER])
{
    for (int i = 0; i < REG_NUMBER; i++)
        new_player->reg[i] = reg[i];
}

void place_player(corewar_t *corewar, struct player *new_player)
{
    int i = 0;
    int f = 0;

    for (; i != new_player->adress; i++);
    for (int j = i; f < new_player->size; j++) {
        corewar->arena[j] = new_player->instructions[f];
        f++;
    }
}

static void fil_new_player(struct player *new_node, corewar_t *corewar,
    struct player *player, unsigned char param)
{
    new_node->magic = player->magic;
    new_node->name = player->name;
    new_node->comment = player->comment;
    new_node->id = player->id;
    if ((player->pc + param % IDX_MOD) > MEM_SIZE)
        player->pc = 0;
    new_node->pc = player->pc + param % IDX_MOD;
    new_node->inst_pos = new_node->pc;
    new_node->adress = player->adress;
    new_node->carry = player->carry;
    new_node->live = player->live;
    new_node->alive = player->alive;
    new_node->cd = 0;
    cp_reg(new_node, corewar->player->reg);
    new_node->instructions = player->instructions;
    new_node->size = player->size;
    new_node->action = NULL;
    new_node->next = NULL;
    place_player(corewar, new_node);
}

static void new_player_func(corewar_t *corewar, struct player **head,
    struct player *player, unsigned char param)
{
    struct player *new_node = NULL;
    struct player *current = NULL;

    new_node = malloc(sizeof(struct player));
    fil_new_player(new_node, corewar, player, param);
    if (*head == NULL) {
        *head = new_node;
    } else {
        current = *head;
        while (current->next != NULL)
            current = current->next;
        new_node->prev = current;
        current->next = new_node;
        new_node->next = NULL;
        current = new_node;
    }
}

int fork_cmd(corewar_t *corewar, struct player *player)
{
    unsigned char param = player->instructions[player->pc + 2];

    new_player_func(corewar, &corewar->player, player, param);
    player->pc += 3;
    corewar->num_fork += 1;
    return 2;
}
