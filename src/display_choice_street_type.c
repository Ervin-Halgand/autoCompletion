/*
** EPITECH PROJECT, 2022
** display_choice_street_type.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

void display_final_choice_specific_to_street_type(t_parsing p, int j,
    char **tab, int input)
{
    for (int i = 0; p.street_name[j][i]; ++i) {
        if (!strncasecmp(&p.street_name[j][i], tab[input - 1],
            strlen(tab[input - 1]))) {
            printf("=> %s, %s %s %s\n", p.city[j], p.number[j],
                p.street_type[j], p.street_name[j]);
            exit(0);
        }
    }
}

void display_choices_street_type(t_parsing p, int nb, int len, char **tab)
{
    size_t size;
    char *buffer = NULL;
    int input = 0;

    printf("\n");
    getline(&buffer, &size, stdin);
    input = atoi(buffer);
    for (int i = 0; tab[i]; ++i)
        if (tab[i][len] != ' ' && tab[i][len] == buffer[0])
            display_final_choice(p.street_name, tab, i, p);
    if (input > nb || isalpha(buffer[0])) {
        dprintf(2, "Unknown address\n");
        exit(84);
    }
    for (int j = 0; p.street_name[j]; ++j)
        display_final_choice_specific_to_street_type(p, j, tab, input);
    exit (0);
}

void manage_street_name_choice(char **tab, int len, t_parsing *p,
    int count_space)
{
    int nb = 0;
    int tmp[1024];

    for (int j = 0; tab[j]; ++j) {
        if (tab[j][len] == ' ') {
            nb++;
            for (int i = 0; p->street_name[i]; ++i) {
                if (!strcasecmp(p->street_name[i], tab[j]))
                    printf("{%i : %s, %s %s ", nb, str_to_upper(p->city[i]),
                        p->number[i], p->street_type[i]);
            }
            if (isupper(tab[j][len]))
                tab[j][len] += 32;
            printf("%s%s}", p->tmp, &tab[j][len]);
            display_space_choice(&count_space);
            tmp[nb - 1] = nb;
            tmp[nb] = -1;
        }
    }
    if (tmp[1] != -1)
        display_choices_street_type(*p, nb, len, tab);
}
