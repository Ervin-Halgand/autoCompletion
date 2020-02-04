/*
** EPITECH PROJECT, 2022
** street_name_equal.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

int get_matched_char(t_parsing p, char **tab)
{
    int b = 0;
    int l = 0;

    for (l = 0; p.street_name[l]; ++l) {
        b = 0;
        for (int i = 0; p.street_name[l][i]; ++i)
            b++;
        if (!tab[0][b + 1])
            break;
    }
    return (l);
}

void display_equal_street_last_name(t_parsing p, char **tmp, char **tmp2,
    int temp)
{
    int nb_enter;
    int count_line = count_nb_line_tab(tmp);
    char *buffer = NULL;
    size_t size;

    printf("\n");
    getline(&buffer, &size, stdin);
    nb_enter = atoi(buffer);
    if (nb_enter > count_line || isalpha(buffer[0])) {
        dprintf(2, "Unknown address\n");
        exit(84);
    }
    for (int i = 1; p.city[temp][i]; ++i)
        if (isupper(p.city[temp][i]))
            p.city[temp][i] += 32;
    printf("=> %s, %s %s %s\n", p.city[temp],
        p.number[temp], tmp[nb_enter - 1], tmp2[nb_enter - 1]);
    exit(0);
}

void get_all_street_name_equal(t_parsing p, char **tab)
{
    int count_line = count_nb_line_tab(tab);
    char **tmp = malloc_tab_whith_line_defined(count_line);
    char **tmp2 = malloc_tab_whith_line_defined(count_line);
    int l = get_matched_char(p, tab);
    int incr = 0;
    int temp;

    temp = l;
    while (count_line > 0) {
        fill_line_tab(tmp, p.street_type[l], incr);
        fill_line_tab(tmp2, p.street_name[l], incr);
        incr++;
        count_line--;
        l++;
    }
    display_equal_street_last_name(p, tmp, tmp2, temp);
}

bool check_matched_equal(char **display)
{
    for (int i = 0; display[i]; ++i) {
        for (int j = 0; display[j]; ++j) {
            if (j == i)
                continue;
            if (strcasecmp(display[i], display[j]))
                return (false);
        }
    }
    return (true);
}

void check_all_street_name_equal(char **display, t_parsing p)
{
    int nb = 0;
    int l;
    char **tmp = erase_special_char(p.street_name);
    char *street_name = NULL;

    if (check_matched_equal(display) == false)
        return;
    for (l = 0; tmp[l]; ++l)
        if (!strcasecmp(tmp[l], display[0]))
            break;
    for (int k = 0; display[k]; ++k) {
        nb++;
        street_name = strdup(p.street_name[l]);
        check_malloc_str(street_name);
        printf("{%i : %s, %s %s %s}", nb, str_to_upper(p.city[l]),
            p.number[l], p.street_type[l], str_to_upper(street_name));
        if (display[k + 1])
            printf(" ");
        l++;
    }
    get_all_street_name_equal(p, display);
}