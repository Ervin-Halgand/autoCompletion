/*
** EPITECH PROJECT, 2022
** display_choice_city.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

void display_final_choice_specific_to_city(t_parsing p, char **tab, int input)
{
    for (int j = 0; p.city[j]; ++j) {
        if (!strcasecmp(p.city[j], tab[input - 1])) {
            printf("=> %s, %s %s %s\n", p.city[j], p.number[j],
                p.street_type[j], p.street_name[j]);
            exit(0);
        }
    }
}

void display_choices_city(t_parsing p, int nb, int len, char **tab)
{
    size_t size;
    char *buffer = NULL;
    int input = 0;

    printf("\n");
    getline(&buffer, &size, stdin);
    input = atoi(buffer);
    for (int i = 0; tab[i]; ++i)
        if (tab[i][len] != ' ' && tab[i][len] == buffer[0])
            display_final_choice(p.city, tab, i, p);
    if (input > nb || isalpha(buffer[0])) {
        dprintf(2, "Unknown address\n");
        exit(84);
    }
    display_final_choice_specific_to_city(p, tab, input);
    exit (0);
}