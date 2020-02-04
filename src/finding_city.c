/*
** EPITECH PROJECT, 2022
** finding_city.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

void free_city(char **display, char **tmp)
{
    for (int j = 0; tmp[j]; ++j)
        free(tmp[j]);
    free(tmp);
    for (int j = 0; display[j]; ++j)
        free(display[j]);
    free(display);
}

char **malloc_new_tab_with_space(char **tmp)
{
    char **tab = NULL;
    int malloc = 0;

    for (int i = 0; tmp[i]; ++i) {
        for (int j = 0; tmp[i][j]; ++j)
            if (tmp[i][j] == ' ')
                malloc++;
        malloc++;
    }
    tab = calloc(sizeof(char*), malloc + 1);
    if (tab == NULL)
        exit (84);
    tab[malloc] = NULL;
    return (tab);
}

void fill_new_tab_with_space(t_increment *var, char **tmp, char **tab, int *c)
{
    char temp[1024];
    bool check_jump = false;
    int b = 0;

    while (tmp[var->y][var->x] == ' ') {
        var->x++;
        check_jump = true;
    }
    if (check_jump == true) {
        while (isalpha(tmp[var->y][var->x])) {
            temp[b] = tmp[var->y][var->x];
            var->x++;
            b++;
        }
        var->x--;
        temp[b] = '\0';
        tab[*c] = strdup(temp);
        check_malloc_str(tab[*c]);
        (*c)++;
    }
}

char **parse_space_city(char **tmp)
{
    char **tab = malloc_new_tab_with_space(tmp);
    int c = 0;
    t_increment var = {0, 0};

    for (var.y = 0; tmp[var.y]; ++var.y) {
        tab[c] = strdup(tmp[var.y]);
        if (tab[c] == NULL)
            exit (84);
        c++;
        for (var.x = 0; tmp[var.y][var.x]; ++var.x)
            fill_new_tab_with_space(&var, tmp, tab, &c);
    }
    return (tab);
}