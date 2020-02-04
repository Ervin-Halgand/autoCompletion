/*
** EPITECH PROJECT, 2022
** project_init.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

void display_h(void)
{
    printf("./autoCompletion -h\n"
           "USAGE\n\t"
           "./autoCompletion dictionary\n\n"
           "DESCRIPTION\n\t"
           "dictionary    file containing one address per line, as "
           "knowledge base");
}

void check_arg(int ac, char **av)
{
    if (ac != 2) {
        dprintf(2, "%s\n", ERROR_ARG);
        exit (ERROR);
    }
    if (av[1] && !strcmp("-h", av[1]))
        display_h();
}

t_parsing init_parsing(char *file)
{
    t_parsing parsing;

    parsing.dictionary = get_file(file);
    parsing.city = get_city(parsing.dictionary);
    parsing.number = get_number(parsing.dictionary);
    parsing.street_type = get_street_type(parsing.dictionary);
    parsing.street_name = get_street_name(parsing.dictionary);
    parsing.buffer = NULL;
    parsing.tmp = NULL;
    parsing.len = 0;
    return (parsing);
}

void free_all(t_parsing parsing)
{
    for (int i = 0; parsing.city[i] != NULL; ++i)
        free(parsing.city[i]);
    for (int i = 0; parsing.street_name[i] != NULL; ++i)
        free(parsing.street_name[i]);
    for (int i = 0; parsing.street_type[i] != NULL; ++i)
        free(parsing.street_type[i]);
    for (int i = 0; parsing.number[i] != NULL; ++i)
        free(parsing.number[i]);
    for (int i = 0; parsing.dictionary[i] != NULL; ++i)
        free(parsing.dictionary[i]);
    if (parsing.street_name != NULL)
        free(parsing.street_name);
    if (parsing.city != NULL)
        free(parsing.city);
    if (parsing.street_type != NULL)
        free(parsing.street_type);
    if (parsing.number != NULL)
        free(parsing.number);
    if (parsing.dictionary != NULL)
        free(parsing.dictionary);
    if (parsing.buffer != NULL)
        free(parsing.buffer);
    if (parsing.tmp != NULL)
        free(parsing.tmp);
}
