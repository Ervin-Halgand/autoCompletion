/*
** EPITECH PROJECT, 2022
** finish.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

bool one_shot_all(t_parsing p, int i, bool *finish)
{
    static int tmp = 0;
    static int nb = 0;

    for (int j = 0; p.city[i][j]; ++j) {
        if (cmp_non_sensitive_char(p.city[i][j], p.buffer[0]) == true) {
            nb++;
            tmp = i;
        }
    }
    if (nb == 1 && p.city[i + 1] == NULL) {
        printf("=> %s, %s %s %s\n", p.city[tmp], p.number[tmp],
            p.street_type[tmp], p.street_name[tmp]);
        *finish = true;
        return (true);
    }
    return (false);
}

bool second_shoot(char **tmp, int counter, t_parsing p, bool *finish)
{
    int i = 0;

    while (tmp[i]) {
        for (int j = 0; p.city[j]; ++j) {
            if (counter == 1 && tmp[i][0] != '\0' &&
                !strcasecmp(p.city[j], tmp[i])) {
                printf("=> %s, %s %s %s\n", p.city[j], p.number[j],
                    p.street_type[j], p.street_name[j]);
                *finish = true;
                return (true);
            }
        }
        i++;
    }
    return (false);
}
char *city_find(char **display)
{
    int count = 0;
    char **tmp = cpy_tab(display);
    char *str = NULL;

    erase_doublon(tmp, tmp);
    for (int j = 0; tmp[j]; ++j) {
        if (tmp[j][0]) {
            str = strdup(tmp[j]);
            check_malloc_str(str);
            count++;
        }
    }
    if (count == 1)
        return (str);
    free(str);
    for (int i = 0; tmp[i]; ++i)
        free(tmp[i]);
    free(tmp);
    return (NULL);
}

char *unknown_adress(int *error, bool *finish)
{
    *error = 84;
    *finish = true;
    dprintf(2, "Unknown address\n");
    exit(84);
//    return (NULL);
}