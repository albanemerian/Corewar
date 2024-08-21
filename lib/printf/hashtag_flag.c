/*
** EPITECH PROJECT, 2023
** hashtag_flags
** File description:
** Some function for space flag
*/

#include <stdlib.h>
#include "struct.h"
#include "my.h"

char *my_put_ohash(char *nb)
{
    char *result = malloc(sizeof(char) * (my_strlen(nb) + 2));

    result[0] = '0';
    for (int i = 1; i <= my_strlen(nb); i++)
        result[i] = nb[i - 1];
    result[my_strlen(nb) + 1] = '\0';
    return (result);
}

char *my_put_oxhash(char *nb)
{
    char *result = malloc(sizeof(char) * (my_strlen(nb) + 3));

    result[0] = '0';
    result[1] = 'x';
    for (int i = 1; i <= my_strlen(nb); i++)
        result[i + 1] = nb[i - 1];
    result[my_strlen(nb) + 2] = '\0';
    return (result);
}

char *my_put_oxhash2(char *nb)
{
    char *result = malloc(sizeof(char) * (my_strlen(nb) + 3));

    result[0] = '0';
    result[1] = 'X';
    for (int i = 1; i <= my_strlen(nb); i++)
        result[i + 1] = nb[i - 1];
    result[my_strlen(nb) + 2] = '\0';
    return (result);
}
