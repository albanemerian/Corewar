/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** flag_handler
*/

#include "corewar.h"

int handle_flags(corewar_t *corewar, char **flag, int *i)
{
    if (strcmp_my(flag[*i], "-dump") == 1) {
        *i += 1;
        if (strcmp_my(flag[*i], "") == 1)
            return 84;
        if (analyse_hexa(corewar, flag[*i]) == 84)
            return 84;
        return 0;
    }
    if (strcmp_my(flag[*i], "-n") == 1) {
        *i += 1;
        if (first_champion(corewar, flag, i) == 84) {
            return 84;
        }
    }
    if (strcmp_my(flag[*i], "-a") == 1) {
        *i += 1;
        if (load_adresses(corewar, flag, i) == 84)
            return 84;
    }
    return 0;
}
