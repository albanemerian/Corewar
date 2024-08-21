/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** init_arena
*/

#include "corewar.h"

static int check_previous(corewar_t *corewar, struct player *current,
    int i)
{
    int distance = MEM_SIZE / corewar->nb_player;

    if (current->adress != -1)
        return 0;
    current->adress = distance * i;
    current->pc = current->adress;
    if (current->adress + current->size > MEM_SIZE)
        return 84;
    return 0;
}

void find_adresses(corewar_t *corewar, struct player *current)
{
    int f = 0;

    current->pc = current->adress;
    for (int j = current->adress; f < current->size; j++) {
        corewar->arena[j] = current->instructions[f];
        f++;
    }
    return;
}

int usee_adresses(corewar_t *corewar)
{
    struct player *current = corewar->player;

    while (current != NULL) {
        find_adresses(corewar, current);
        current = current->next;
    }
    corewar->cycle_to_die = CYCLE_TO_DIE;
    corewar->live_cycle = 0;
    corewar->total_cycle = 0;
    corewar->num_fork = corewar->nb_player;
    return 0;
}

int place_players(corewar_t *corewar)
{
    struct player *current = corewar->player;
    int i = 0;

    while (current != NULL) {
        if (current->adress + current->size > MEM_SIZE) {
            print("Incorrect load adress\n");
            return 84;
        }
        if (check_previous(corewar, current, i) == -1)
            return 84;
        i++;
        current = current->next;
    }
    if (usee_adresses(corewar) == 84)
        return 84;
    return 0;
}

static int loop_game(corewar_t *corewar)
{
    struct player *current = corewar->player;

    while (current != NULL) {
        if (current->action != NULL)
            make_instruction(corewar, current);
        else {
            create_action(current, corewar);
            current->cd -= 1;
        }
        current = current->next;
    }
    return 0;
}

static int change_varible(corewar_t *corewar)
{
    if (corewar->live_cycle >= NBR_LIVE) {
        corewar->cycle_to_die -= CYCLE_DELTA;
        corewar->live_cycle = 0;
    }
    if (corewar->dump_flag == true && corewar->total_cycle >=
        corewar->nb_cycle) {
        if (check_live(corewar) == true)
            print("The player 0() has won.\n");
        return 1;
    }
    corewar->total_cycle += 1;
    return 0;
}

static int create_area(corewar_t *corewar)
{
    for (int i = 0; i < MEM_SIZE; i++)
        corewar->arena[i] = 0x00;
    if (place_players(corewar) == 84)
        return 84;
    return 0;
}

static int loop(corewar_t *corewar, int x, bool live)
{
    loop_game(corewar);
    if (x == corewar->cycle_to_die) {
        live = check_live(corewar);
        if (live == false)
            return 84;
        x = 0;
    }
    if (change_varible(corewar) == 1)
        return 84;
    x++;
    return 0;
}

int init_arena(corewar_t *corewar)
{
    int x = 0;
    bool live = true;

    if (create_area(corewar) == 84)
        return 84;
    while (1) {
        if (loop(corewar, x, live) == 84)
            break;
    }
    if (corewar->dump_flag == true)
        print_arena(corewar->arena, corewar);
    return 0;
}
