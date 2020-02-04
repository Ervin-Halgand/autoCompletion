/*
** EPITECH PROJECT, 2022
** display_street_type.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

bool check_finish(int *nb, bool *finish, t_parsing p)
{
    int check = 0;

    for (int i = 0; nb[i] != -1; ++i)
        check++;
    if (check == 1) {
        printf("=> %s, %s %s %s\n", p.city[nb[0]], p.number[nb[0]],
            p.street_type[nb[0]], p.street_name[nb[0]]);
        *finish = true;
        return (true);
    }
    return (false);
}

void streetname_not_found_new_choice(char **final, char *city)
{
    int count = 0;

    for (int i = 0; final[i]; ++i) {
        if (final[i][0] != '\0')
            count++;
    }
    if (count > 5)
        count = 5;
    for (int l = 0; city[l]; ++l)
        if (!isupper(city[l]))
            city[l] -= 32;
    for (int j = 0; j < count; ++j) {
        printf("{%s, %s}", city, final[j]);
        if (j + 1 < count)
            printf(" ");
    }
    for (int k = 0; final[k]; ++k)
        free(final[k]);
    free(final);
    printf("\n");
}

void street_name_oneshot(char **final, t_parsing p)
{
    for (int i = 0; p.street_name[i]; ++i) {
        for (int j = 0; p.street_name[i][j]; ++j) {
            if (!strncasecmp(&p.street_name[i][j], final[0], strlen(final[0]))) {
                printf("=> %s, %s %s %s\n", p.city[i], p.number[i],
                    p.street_type[i], p.street_name[i]);
                exit (0);
            }
        }
    }
}

void manage_street_name_step(char **only_match,t_parsing *p, int counter,
    char *city)
{
    bool dont_display = false;

    if (counter == 1)
        street_name_oneshot(only_match, *p);
    only_match = display_adresse(only_match, p, &dont_display, true);
    if (dont_display == true)
        streetname_not_found_new_choice(only_match, city);
    else
        printf("\n");
}

char *check_street_name(t_parsing *p, char *city, bool *finish, int *error)
{
    char **street_name = cpy_tab(p->street_name);
    int *number = get_occurence(p->city, city);
    char **only_match = NULL;
    static unsigned int i = 0;
    int counter = 0;

    if (i++ == 0)
        init_buffer(p);
    if (number == NULL)
        return (unknown_adress(error, finish));
    if (check_finish(number, finish, *p) == true)
        return (NULL);
    only_match = get_matched_to_buffer_first_time(street_name, number);
    only_match = parse_space_city(only_match);
    if (strlen(p->tmp) != 0) {
        only_match = get_matched_to_buffer(only_match, *p, &counter);
        if (only_match[0] == NULL)
            return (unknown_adress(error, finish));
    }
    manage_street_name_step(only_match, p, counter, city);
    return (NULL);
}