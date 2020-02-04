/*
** EPITECH PROJECT, 2022
** parse_street_type.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

char *get_malloc_line_type(char *line, char *to_malloc, char **type)
{
    int i = 0;
    int check = false;

    while (line[i]) {
        while (line[i] >= '0' && line[i] <= '9') {
            i++;
            check = true;
        }
        i++;
        if (check == true)
            break;
    }
    for (int j = 0; type[j]; ++j) {
        if (!strncmp(&line[i], type[j], strlen(type[j]))) {
            to_malloc = strdup(type[j]);
            check_malloc_str(to_malloc);
            break;
        }
    }
    return (to_malloc);
}

char **fill_street_type_tab()
{
    char **tab = NULL;
    int i;

    if ((tab = calloc(sizeof(char*), 10)) == NULL)
        exit (84);
    tab[0] = strdup("allée");
    tab[1] = strdup("avenue");
    tab[2] = strdup("boulevard");
    tab[3] = strdup("chemin");
    tab[4] = strdup("impasse");
    tab[5] = strdup("place");
    tab[6] = strdup("quai");
    tab[7] = strdup("rue");
    tab[8] = strdup("square");
    tab[9] = NULL;
    for (i = 0; tab[i]; ++i)
        check_malloc_str(tab[i]);
    if (i != 9)
        exit (84);
    return (tab);
}

char **get_street_type(char **dictionary)
{
    char **street_type = NULL;
    char **type = fill_street_type_tab();
    int count = 0;

    while (dictionary[count] != NULL)
        count++;
    if (!(street_type = calloc(sizeof(char*), count + 1)))
        exit (84);
    street_type[count] = NULL;
    for (int i = 0; dictionary[i]; i++)
        street_type[i] = get_malloc_line_type(dictionary[i], street_type[i],
            type);
    for (int j = 0; type[j]; ++j)
        free(type[j]);
    free(type);
    return (street_type);
}