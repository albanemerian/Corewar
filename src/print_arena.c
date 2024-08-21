/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** print_arena
*/

#include "corewar.h"


void print_lines_side(int lines)
{
    if (my_strlen(convert_base(my_itoa(lines), "0123456789",
        "0123456789ABCDEF")) < 2) {
        my_printf("N°%s    | ", convert_base(my_itoa(lines), "0123456789",
            "0123456789ABCDEF"));
        return;
    }
    if (my_strlen(convert_base(my_itoa(lines), "0123456789",
        "0123456789ABCDEF")) < 3) {
        my_printf("N°%s   | ", convert_base(my_itoa(lines), "0123456789",
            "0123456789ABCDEF"));
        return;
    }
    if (my_strlen(convert_base(my_itoa(lines), "0123456789",
        "0123456789ABCDEF")) < 4) {
        my_printf("N°%s  | ", convert_base(my_itoa(lines), "0123456789",
            "0123456789ABCDEF"));
        return;
    } else
        my_printf("N°%s | ", convert_base(my_itoa(lines), "0123456789",
            "0123456789ABCDEF"));
}

void print_header(corewar_t *corewar)
{
    int f = 0;
    struct player *current = corewar->player;

    for (; f < corewar->nb_player; f++)
        print("\tName\tID:");
    print("\n");
    for (int j = 0; j < corewar->nb_player; j++) {
        print("\t%s\t%d", current->name, current->id);
        current = current->next;
    }
    my_printf("\n");
}

void print_arena(unsigned char arena[MEM_SIZE], corewar_t *corewar)
{
    int count = 0;
    int lines = 0;

    print_header(corewar);
    for (int i = 0; i < 105; i++)
        print("-");
    print("\nN°%i    | ", lines);
    for (int i = 0; i < MEM_SIZE; i++) {
        if (count == 32) {
            count = 0;
            print(" |\n");
            lines += 32;
            print_lines_side(lines);
        }
        my_printf("%02x ", arena[i]);
        count++;
    }
    my_printf(" |\n\n");
}
