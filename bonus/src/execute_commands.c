/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** execute_commands
*/

#include "corewar.h"

const unsigned char fm[17] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10};

const int (*inst[17])(corewar_t *, struct player *) = {
    &live, &ld_cmd, &st_cmd, &add, &sub, &and_cmd, &or_cmd,
    &xor_cmd, &zjmp, &ldi, &sti, &fork_cmd, &lld, &lldi, &lfork, &aff};

const int cooldown[17] = {10, 5, 5, 10, 10, 6, 6, 6, 20, 25, 25, 800, 10, 50,
    1000, 2};

void restart_cycle(struct player **player)
{
    struct player *temp = *player;

    while (*player != NULL) {
        (*player)->action = NULL;
        (*player)->cd = 0;
        (*player) = (*player)->next;
    }
    *player = temp;
}

void make_instruction(corewar_t *corewar, struct player *current)
{
    int result = 0;

    if (current->cd == 0) {
        result = current->action(corewar, current);
        if (result == 0)
            current->carry = 0;
        if (result == 1)
            current->carry = 1;
        current->action = NULL;
        current->cd = 0;
    } else {
        current->cd -= 1;
    }
}

void create_action(struct player *current)
{
    for (int i = 0; i < 16; i++) {
        if (current->instructions[current->pc] == fm[i]) {
            current->action = inst[i];
            current->cd = cooldown[i];
            break;
        }
    }
}
