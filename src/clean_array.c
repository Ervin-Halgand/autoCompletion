/*
** EPITECH PROJECT, 2022
** clean_array.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

char **erase_unsed(char **tmp, t_parsing p, int *counter, int len)
{
    int i = 0;

    while (tmp[i]) {
        if (!strncasecmp(tmp[i], p.tmp, len))
            (*counter)++;
        else
            tmp[i][0] = '\0';
        i++;
    }
    return (tmp);
}

void erase(char **tmp, char **tmp2, int k)
{
    for (int i = k + 1; tmp[i]; ++i) {
        if (tmp[i][0] != '\0' && tmp[k][0] != '\0' &&
            !strcasecmp(tmp[k], tmp[i])) {
            tmp2[i][0] = '\0';
        }
    }
}

void erase_doublon(char **tmp, char **tmp2)
{
    for (int k = 0; tmp[k]; ++k) {
        erase(tmp, tmp2, k);
    }
}

char **new_tab_without_empty_line(char **tmp)
{
    int count = 0;
    char **final = NULL;
    int incr = 0;

    for (int j = 0; tmp[j]; ++j)
        if (tmp[j][0] != '\0')
            count++;
    if ((final = calloc(sizeof(char*), count + 1)) == NULL)
        exit(84);
    final[count] = NULL;
    for (int i = 0; tmp[i]; ++i) {
        if (tmp[i][0] != '\0') {
            final[incr] = strdup(tmp[i]);
            check_malloc_str(final[incr]);
            incr++;
        }
    }
    return (final);
}