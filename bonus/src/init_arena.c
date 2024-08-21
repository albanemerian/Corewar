/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** init_arena
*/

#include "corewar.h"

static int check_previous(corewar_t *corewar, struct player *current, int i)
{
    int temp = i;

    if (current->adress == -1) {
        current->adress = (MEM_SIZE / (temp) - current->size) / 2;
        if (current->adress < 0)
            return 84;
    }
    return 0;
}

void find_adresses(corewar_t *corewar, struct player *current)
{
    int f = 0;
    int i = 0;

    for (; i != current->adress; i++);
    for (int j = i; f < current->size; j++) {
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
    return 0;
}

int place_players(corewar_t *corewar)
{
    struct player *current = corewar->player;
    int i = corewar->nb_player;

    while (current != NULL) {
        if (current->adress + current->size > MEM_SIZE) {
            print("Incorrect load adress\n");
            return 84;
        }
        if (check_previous(corewar, current, i) == -1)
            return 84;
        i--;
        current = current->next;
    }
    if (usee_adresses(corewar) == 84)
        return 84;
    return 0;
}

bool check_live(corewar_t *corewar)
{
    struct player *current = corewar->player;
    int nb = 0;
    char *winner = NULL;

    while (current != NULL) {
        if (current->alive == false)
            nb++;
        winner = my_strdup(current->name);
        current = current->next;
    }
    if (nb == corewar->nb_player - 1) {
        print("The winner is %s\n", winner);
        return false;
    }
    return true;
}

static int loop_game(corewar_t *corewar)
{
    struct player *current = NULL;

    current = corewar->player;
    for (int i = 0; current != NULL; i++) {
        if (current->size <= current->pc)
            current->pc = 0;
        if (current->action != NULL) {
            make_instruction(corewar, current);
        } else {
            create_action(current);
            current->cd -= 1;
        }
        current = current->next;
    }
    return 0;
}

void print_arena(unsigned char arena[MEM_SIZE], int size)
{
    for (int i = 0; i < size; i++) {
        if (arena[i] == 0) {
            printf("%d", arena[i]);
        } else {
            printf("%x", arena[i]);
        }
    }
    printf("\n");
}


int init_arena(corewar_t *corewar)
{
    int x = 0;

    for (int i = 0; i < MEM_SIZE; i++)
        corewar->arena[i] = 0x00;
    if (place_players(corewar) == 84)
        return 84;
    print_arena(corewar->arena, MEM_SIZE);
    for (int i = 0; check_live(corewar) == true; i++) {
        print("[%d]\n", i);
        loop_game(corewar);
        x++;
        if (x > corewar->nb_cycle) {
            x = 0;
            break;
        }
    }
    print_arena(corewar->arena, MEM_SIZE);
    return 0;
}
