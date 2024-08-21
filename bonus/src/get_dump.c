/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** get_dump
*/

#include "corewar.h"

static int get_cycles(char *dup, int temp, corewar_t *corewar)
{
    char *convert = NULL;

    convert = convert_base(dup, "0123456789ABCDEF", "0123456789");
    temp = my_getnbr(convert);
    free(dup);
    if (temp <= 0) {
        write(2, "Invalid number of cycles\n", 26);
        return 84;
    }
    return temp;
}

int analyse_hexa(corewar_t *corewar, char *flag)
{
    int temp = 0;
    char *dup = NULL;

    for (int i = 0; flag[i] != '\0'; i++) {
        if ((flag[i] < 48 || flag[i] > 57) && (flag[i] < 65 || flag[i] > 70)) {
            write(2, "Invalid number of cycles\n", 26);
            return 84;
        }
    }
    dup = my_strdup(flag);
    corewar->nb_cycle = get_cycles(dup, temp, corewar);
    if (corewar->nb_cycle == 84)
        return 84;
    corewar->dump = my_strdup(flag);
    return 0;
}
