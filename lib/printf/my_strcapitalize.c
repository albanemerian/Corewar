/*
** EPITECH PROJECT, 2023
** my_strcapitalize
** File description:
** Turn string in ~word~
*/

static char *turn_lowcase(char *str, int i)
{
    if (str[i - 1] >= 'A' && str[i - 1] <= 'Z' ||
        (str[i - 1] >= 'a' && str[i - 1] <= 'z'))
        str[i] += 32;
    return (str);
}

static char *turn_upcase(char *str, int i)
{
    if (str[i - 1] < '0' || str[i - 1] > 'z' ||
        (str[i - 1] > 'Z' && str[i - 1] < 'a') ||
        (str[i - 1] > '9' && str[i - 1] < 'A'))
        str[i] -= 32;
    return (str);
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] -= 32;
        if ((str[i] >= 'a' && str[i] <= 'z') && i > 0)
            str = turn_upcase(str, i);
        if ((str[i] >= 'A' && str[i] <= 'Z') && i > 0)
            str = turn_lowcase(str, i);
    }
    return (str);
}
