/*
** EPITECH PROJECT, 2022
** tools.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

bool cmp_non_sensitive_char(char str1, char str2)
{
    if (str1 == str2)
        return (true);
    str1 += 32;
    if (str1 == str2)
        return (true);
    str1 -= 64;
    if (str1 == str2)
        return (true);
    return (false);
}

char **cpy_tab(char **tab)
{
    int g = 0;
    char **tmp = NULL;

    while (tab[g])
        g++;
    tmp = calloc(sizeof(char*), g + 1);
    if (tmp == NULL)
        exit (84);
    tmp[g] = NULL;
    g = 0;
    while (tab[g]) {
        tmp[g] = strdup(tab[g]);
        g++;
    }
    return (tmp);
}

void fill_line_tab(char **tab, char *str, int i)
{
    tab[i] = strdup(str);
    check_malloc_str(tab[i]);
}

int count_space_tab(char **tab, int len)
{
    int count_space = 0;

    for (int k = 0; tab[k]; ++k) {
        if (tab[k][len] == ' ')
            count_space++;
    }
    count_space--;
    return (count_space);
}