/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** handle_file
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "corewar.h"


static int find_ids(corewar_t *corewar, char *file,
    unsigned char *buffer, size_t size)
{
    corewar->temp_size = size;
    if (creat_list(&corewar->player, corewar, file, buffer) == 84)
        return 84;
    corewar->temp_size = 0;
    corewar->nb_player += 1;
    return 0;
}

static long size_file(char *file)
{
    FILE *fd = fopen(file, "rb");
    unsigned char buff;
    int size = 0;

    if (fd == NULL)
        return -1;
    for (; fread(&buff, 1, 1, fd); size++);
    fclose(fd);
    return (size);
}

int handle_file(corewar_t *corewar, char **champion,
    char *file)
{
    long size = size_file(file);
    FILE *fd = fopen(file, "rb");
    unsigned char *buffer = NULL;
    size_t bytes_ead = 0;

    if (size == -1)
        return 84;
    if (fd == NULL)
        return 84;
    buffer = malloc(sizeof(char) * size + 1);
    bytes_ead = fread(buffer, 1, size, fd);
    if (bytes_ead != size) {
        free(buffer);
        return 84;
    }
    fclose(fd);
    buffer[size] = '\0';
    if (find_ids(corewar, file, buffer, size) == 84)
        return 84;
    return 0;
}
