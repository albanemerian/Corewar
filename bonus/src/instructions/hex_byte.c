/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** hex_byte
*/

#include "corewar.h"

void calculate_pc(struct player *current)
{
    print("current -> pc = %d\n", current->pc);
    for (int i = 0; i < 3; i++) {
        if (current->types[i] == T_REG)
            current->pc += 1;
        if (current->types[i] == T_DIR)
            current->pc += DIR_SIZE;
        if (current->types[i] == T_IND)
            current->pc += IND_SIZE;
    }
    current->pc += 2;
}

void restart_type(struct player *current)
{
    for (int i = 0; i < 3; i++)
        current->types[i] = 0;
}

void find_type(struct player *current, char *binary)
{
    char **array = malloc(sizeof(char *) * 4);

    array[0] = my_strndup(binary, 2);
    array[1] = my_strndup(binary + 2, 2);
    array[2] = my_strndup(binary + 4, 2);
    array[3] = NULL;
    for (int i = 0; array[i] != NULL; i++) {
        if (strcmp_my(array[i], "01") == 1)
            current->types[i] = T_REG;
        if (strcmp_my(array[i], "10") == 1)
            current->types[i] = T_DIR;
        if (strcmp_my(array[i], "11") == 1)
            current->types[i] = T_IND;
    }
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    return;
}

char *hex_byte(struct player *current, unsigned char hex_byte)
{
    char *binary = malloc(sizeof(char) * 9);
    int index = 0;

    for (int i = 7; i >= 0; --i) {
        binary[index] = ((hex_byte >> i) & 1) + '0';
        index++;
    }
    binary[index] = '\0';
    return binary;
}
