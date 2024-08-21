/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** get_adresses
*/

#include "corewar.h"

int realloc_tab(corewar_t *corewar, int temp)
{
    int *temp2 = NULL;

    if (corewar->nb_player < 0) {
        temp2 = realloc(corewar->adresses, sizeof(int) *
            (corewar->nb_player + 1));
        if (temp2 == NULL)
            return 84;
        corewar->adresses = temp2;
    }
    corewar->adresses[corewar->nb_player] = temp;
    return 0;
}

int load_adresses(corewar_t *corewar, char **flag, int *i)
{
    int temp = 0;

    if (strcmp_my(flag[*i], "") == 1) {
        write(2, "Error: No adresses\n", 20);
        return 84;
    }
    for (int j = 0; flag[*i][j] != '\0'; j++) {
        if (flag[*i][j] < '0' || flag[*i][j] > '9') {
            write(2, "Error: Adresses must be numbers\n", 33);
            return 84;
        }
    }
    temp = my_getnbr(flag[*i]);
    if (realloc_tab(corewar, temp) == 84)
        return 84;
    corewar->bool_adress = true;
    return 0;
}
