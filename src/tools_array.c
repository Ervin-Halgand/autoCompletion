/*
** EPITECH PROJECT, 2022
** tools_array.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

void check_if_is_special_char_malloc(char **to_erase, int i, int *count_malloc)
{
    for (int j = 0; to_erase[i][j]; ++j)
        if (to_erase[i][j] != '\'' && to_erase[i][j] != '-')
            (*count_malloc)++;
}

void check_if_is_special_char_swapping(char **to_erase, int i, int *count,
    char **new_tab)
{
    for (int j = 0; to_erase[i][j]; ++j)
        if (to_erase[i][j] != '\'' && to_erase[i][j] != '-') {
            new_tab[i][*count] = to_erase[i][j];
            (*count)++;
        }
}

char **erase_special_char(char **to_erase)
{
    char **new_tab = NULL;
    int count_malloc = 0;

    while (to_erase[count_malloc])
        count_malloc++;
    if ((new_tab = calloc(sizeof(char*), count_malloc + 1)) == NULL)
        exit (84);
    new_tab[count_malloc] = NULL;
    for (int i = 0; to_erase[i]; ++i) {
        count_malloc = 0;
        check_if_is_special_char_malloc(to_erase, i, &count_malloc);
        new_tab[i] = calloc(sizeof(char), count_malloc + 1);
        check_malloc_str(new_tab[i]);
        new_tab[i][count_malloc] = '\0';
        count_malloc = 0;
        check_if_is_special_char_swapping(to_erase, i, &count_malloc, new_tab);
    }
    return (new_tab);
}

int count_nb_line_tab(char **tab)
{
    int i = 0;

    while (tab[i])
        i++;
    return (i);
}

char **malloc_tab_whith_line_defined(int line)
{
    char **tab = NULL;

    if ((tab = calloc(sizeof(char*), line + 1)) == NULL)
        exit(84);
    tab[line] = NULL;
    return (tab);
}