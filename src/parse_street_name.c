/*
** EPITECH PROJECT, 2022
** parse_street_name.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

char *replace_end_of_line(int nb, char *line, char *to_malloc)
{
    if (line[strlen(line) - 1] == '\n') {
        to_malloc = strndup(&line[nb], strlen(&line[nb]) - 1);
        check_malloc_str(to_malloc);
    }
    else {
        to_malloc = strdup(&line[nb]);
        check_malloc_str(to_malloc);
    }
    return (to_malloc);
}

int get_line_type(char **type, bool *check, char *line, int nb)
{
    int j = 0;

    while (type[j]) {
        if (!strncmp(&line[nb], type[j], strlen(type[j]))) {
            *check = true;
            break;
        }
        j++;
    }
    return (j);
}

char *get_malloc_line_name(char *line, char *to_malloc, char **type)
{
    int nb = 0;
    int j = 0;
    bool check = false;

    while (line[nb]) {
        j = get_line_type(type, &check, line, nb);
        nb++;
        if (check == true)
            break;
    }
    nb += strlen(type[j]);
    to_malloc = replace_end_of_line(nb, line, to_malloc);
    return (to_malloc);
}

char **get_street_name(char **dictionary)
{
    char **street_name = NULL;
    char **type = fill_street_type_tab();
    int count = 0;

    while (dictionary[count] != NULL)
        count++;
    street_name = calloc(sizeof(char*), count + 1);
    if (street_name == NULL)
        exit (84);
    street_name[count] = NULL;
    for (int i = 0; dictionary[i]; i++) {
        street_name[i] = get_malloc_line_name(dictionary[i], street_name[i],
            type);
    }
    for (int j = 0; type[j]; ++j)
        free(type[j]);
    free(type);
    return (street_name);
}