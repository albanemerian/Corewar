/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** get_prog_number
*/

#include "corewar.h"

int check_id(corewar_t *corewar, char **flag, int *i)
{
    for (int j = 0; corewar->ids[j] != NULL; j++) {
        if (strcmp_my(corewar->ids[j], flag[*i]) == 1) {
            write(2, "Invalid champion number\n", 25);
            return 84;
        }
    }
    return 0;
}

static int handle_id(corewar_t *corewar, char **flag, int *i)
{
    char **temp = NULL;
    int nb = my_getnbr(flag[*i]);

    if (nb <= 0) {
        write(2, "Invalid champion number\n", 25);
        return 84;
    }
    if (corewar->nb_player > 0) {
        temp = realloc(corewar->ids, sizeof(char *) *
            (corewar->nb_player + 1));
        if (temp == NULL)
            return 84;
        corewar->ids = temp;
    }
    corewar->bool_id = true;
    return 0;
}

int first_champion(corewar_t *corewar, char **flag, int *i)
{
    if (check_id(corewar, flag, i) == 84)
        return 84;
    for (int j = 0; flag[*i][j] != '\0'; j++) {
        if (flag[*i][j] < 48 || flag[*i][j] > 57) {
            write(2, "Invalid champion number\n", 25);
            return 84;
        }
    }
    if (handle_id(corewar, flag, i) == 84)
        return 84;
    corewar->ids[corewar->nb_player] = my_strdup(flag[*i]);
    return 0;
}
