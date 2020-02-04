/*
** EPITECH PROJECT, 2022
** parse_city.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

char *get_malloc_line(char *line, char *to_malloc)
{
    int nb = 0;

    while (line[nb] != ',')
        nb++;
    to_malloc = calloc(sizeof(char), nb + 1);
    check_malloc_str(to_malloc);
    to_malloc[nb] = '\0';
    return (to_malloc);
}

char **get_city(char **dictionary)
{
    char **city = NULL;
    int count = 0;

    while (dictionary[count] != NULL)
        count++;
    if (!(city = calloc(sizeof(char*), count + 1)))
        exit (84);
    city[count] = NULL;
    for (int i = 0; dictionary[i]; i++) {
        city[i] = get_malloc_line(dictionary[i], city[i]);
        for (int j = 0; dictionary[i][j] != ','; j++)
            city[i][j] = dictionary[i][j];
    }
    return (city);
}