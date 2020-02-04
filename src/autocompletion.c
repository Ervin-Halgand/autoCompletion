/*
** EPITECH PROJECT, 2022
** autocompletion.c
** File description:
** Created by Ervin,
*/

#include <printf.h>
#include "../include/autocompletion.h"

int loop(t_parsing parsing)
{
    char *city = NULL;
    bool finish = false;
    int error = 0;

    while (error != 84 && parsing.len != -1) {
        if (city == NULL)
            city = check_city(&parsing, &finish, parsing.len, &error);
        if (finish == true)
            break;
        if (city != NULL)
            check_street_name(&parsing, city, &finish, &error);
        if (finish == true)
            break;
        if (new_buffer(&parsing) == false)
            break;
    }
    if (error == 84)
        return (ERROR);
    return (0);
}

int main(int ac, char **av)
{
    t_parsing parsing;
    int error = 0;

    check_arg(ac, av);
    parsing = init_parsing(av[1]);
    init_buffer(&parsing);
    error = loop(parsing);
    if (error == 84)
        return (ERROR);
    free_all(parsing);
    return (0);
}