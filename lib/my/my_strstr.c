/*
** EPITECH PROJECT, 2023
** my_strstr
** File description:
** find a needle in a haystack
*/

#include <stdlib.h>
#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int letter = 0;

    if (my_strlen(to_find) > my_strlen(str))
        return (NULL);
    if (my_strlen(to_find) == 0)
        return (str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_strncmp(&str[i], to_find, my_strlen(to_find)) == 0)
            return (&str[i]);
    }
    return (NULL);
}

// char *my_strstr(const char *str, char *c)
// {
//     while (*str != '\0') {
//         if (*str == c) {
//             return (str);
//         }
//         str++;
//     }
//     return NULL;
// }
