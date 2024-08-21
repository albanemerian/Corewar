/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** end_condition
*/

#include "corewar.h"

static int print_end(corewar_t *corewar, char *winner, int id, int nb)
{
    if (nb == corewar->nb_player) {
        print("The player 0() has won.\n");
        return 1;
    }
    if (nb == corewar->num_fork - 1) {
        print("The player N°%i %s has won\n", id, winner);
        free(winner);
        return 1;
    }
    return 0;
}

bool check_live(corewar_t *corewar)
{
    struct player *current = corewar->player;
    int nb = 0;
    char *winner = NULL;
    int id = 0;

    if (check_memory(corewar) == false)
        return false;
    while (current != NULL) {
        if (current->alive == false)
            nb++;
        else {
            winner = my_strdup(current->name);
            id = current->id;
        }
        current = current->next;
    }
    if (print_end(corewar, winner, id, nb) == 1)
        return false;
    free(winner);
    return true;
}
