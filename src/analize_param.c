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
