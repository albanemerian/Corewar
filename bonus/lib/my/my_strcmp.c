/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** Compare 2 strings
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    if (*s1 - *s2 < 0)
        return (-1);
    if (*s1 - *s2 > 0)
        return (1);
    return (0);
}

int strcmp_my(char const *s1, char const *s2)
{
    int s1_len = my_strlen(s1);
    int s2_len = my_strlen(s2);

    if (s1_len != s2_len)
        return 0;
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return (0);
        }
    }
    return 1;
}
