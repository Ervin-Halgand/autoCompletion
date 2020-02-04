/*
** EPITECH PROJECT, 2022
** street_name_tools.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

char **get_matched_to_buffer_first_time(char **name, int *nb)
{
    char **new = NULL;
    int malloc = 0;

    for (int i = 0; nb[i] != -1; ++i)
        malloc++;
    if ((new = calloc(sizeof(char*), malloc + 1)) == NULL)
        return (NULL);
    new[malloc] = NULL;
    for (int j = 0; j < malloc; ++j) {
        new[j] = strdup(name[nb[j]]);
        check_malloc_str(new[j]);
    }
    return (new);
}

char **get_matched_to_buffer(char **name, t_parsing pars, int *counter)
{
    char **new = NULL;
    int incr = 0;

    for (int i = 0; name[i]; ++i)
        if (!strncasecmp(pars.tmp, name[i], strlen(pars.tmp))) {
            (*counter)++;
        }
    if ((new = calloc(sizeof(char*), (*counter) + 1)) == NULL)
        return (NULL);
    new[(*counter)] = NULL;
    for (int j = 0; name[j]; ++j) {
        if (!strncasecmp(pars.tmp, name[j], strlen(pars.tmp))) {
            new[incr] = strdup(name[j]);
            check_malloc_str(new[incr]);
            incr++;
        }
    }
    return (new);
}

char **parse_tab_to_match_to_buffer(int check, t_parsing *p, char **display)
{
    char **final = new_tab_without_empty_line(display);
    int new = count_new_buffer(final, p->tmp);

    if (final[0] != NULL && new != 0) {
        p->tmp = strndup(final[0], new);
        check_malloc_str(p->tmp);
    }
    for (int i = 0; i < check; ++i) {
        final[i] = strndup(display[i], new + 1);
        check_malloc_str(final[i]);
    }
    return (final);
}