/*
** EPITECH PROJECT, 2023
** main
** File description:
** main function of Corewar
*/

#include "corewar.h"

int main(int ac, char **av)
{
    if (ac == 2) {
        if (strcmp_my(av[1], "-h") == 1)
            return helper();
    }
    if (ac < 3)
        return 84;
    if (analyse_params(ac, av) == 84)
        return 84;
    return 0;
}
