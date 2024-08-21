/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** analize_param
*/

#include "corewar.h"

int handle_champions(corewar_t *corewar, char **champion, char *filename)
{
    if (handle_file(corewar, champion, filename) == 84)
        return 84;
    return 0;
}

int analize_flags(corewar_t *corewar, char **av, int *i)
{
    if (av[*i][0] == '-') {
        if (handle_flags(corewar, av, i) == 84)
            return 84;
    } else {
        if (handle_champions(corewar, av, av[*i]) == 84)
            return 84;
    }
    return 0;
}

void print_player(corewar_t *corewar)
{
    struct player *current = corewar->player;

    while (current != NULL) {
        print("Magic %x\n", current->magic);
        print("Player N°%i\t Name %s\n", current->id, current->name);
        print("Comment %s\n", current->comment);
        print("Size %i\t", current->size);
        print("Adress %i\n", current->adress);
        print("PC %i\t", current->pc);
        print("Carry %i\t", current->carry);
        print("Live %i\n", current->live);
        print("Instructions:\n[%s]\n", current->instructions);
        print("\n");
        current = current->next;
    }
    print("Num player: %i\n", corewar->nb_player);
    free_func(corewar);
    return;
}

int analyse_params(int ac, char **av)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));

    init_struct(corewar);
    for (int i = 1; av[i] != NULL; i++) {
        if (analize_flags(corewar, av, &i) == 84) {
            free_func(corewar);
            return 84;
        }
    }
    if (corewar->nb_player < 2) {
        write(2, "Not enough champions\n", 21);
        free_func(corewar);
        return 84;
    }
    if (init_arena(corewar) == 84) {
        free_func(corewar);
        return 84;
    }
    return 0;
}
