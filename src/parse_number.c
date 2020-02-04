/*
** EPITECH PROJECT, 2022
** parse_number.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

char *get_malloc_line_nb(char *line, char *to_malloc)
{
    int nb = 0;
    int i = 0;

    while (line[i]) {
        if (line[i] >= '0' && line[i] <= '9')
            nb++;
        i++;
    }
    to_malloc = calloc(sizeof(char), nb + 1);
    check_malloc_str(to_malloc);
    to_malloc[nb] = '\0';
    return (to_malloc);
}

void fill_number_condition(char **dictionary, int i, char **number)
{
    int nb = 0;

    for (int j = 0; dictionary[i][j]; j++)
        if (dictionary[i][j] >= '0' && dictionary[i][j] <= '9') {
            number[i][nb] = dictionary[i][j];
            nb++;
        }
}

char **get_number(char **dictionary)
{
    char **number = NULL;
    int count = 0;

    while (dictionary[count] != NULL)
        count++;
    number = calloc(sizeof(char*), count + 1);
    if (number == NULL)
        exit (84);
    number[count] = NULL;
    for (int i = 0; dictionary[i]; i++) {
        number[i] = get_malloc_line_nb(dictionary[i], number[i]);
        fill_number_condition(dictionary, i, number);
    }
    return (number);
}