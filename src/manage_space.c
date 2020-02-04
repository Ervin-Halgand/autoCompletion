/*
** EPITECH PROJECT, 2022
** manage_space.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

void display_final_choice(char **final, char **tab, int i, t_parsing  p)
{
    for (int j = 0; final[j]; ++j) {
        if (!strcasecmp(p.city[j], tab[i])) {
            printf("=> %s, %s %s %s\n", p.city[j], p.number[j],
                p.street_type[j], p.street_name[j]);
            exit(0);
        }
    }
}

void display_space_choice(int *count_space)
{
    if (*count_space > 0) {
        printf(" ");
        (*count_space)--;
    }
}

void manage_city_choice(char **tab, int len, t_parsing *p, int count_space)
{
    int nb = 0;

    for (int j = 0; tab[j]; ++j) {
        if (tab[j][len] == ' ') {
            nb++;
            if (isupper(tab[j][len]))
                tab[j][len] += 32;
            printf("{%i : %s%s}", nb, p->tmp, &tab[j][len]);
            display_space_choice(&count_space);
        }
    }
    display_choices_city(*p, nb, len, tab);
}

int check_str_len_space(int len, char **tab)
{
    for (int m = 0; tab[m]; ++m) {
        for (int i = 0; tab[m][i]; ++i)
            if (tab[m][i] == ' ' && len > i)
                len = i;
    }
    return (len);
}

bool manage_space(t_parsing *p, char **tab, bool step)
{
    int count_space = 0;
    int len = strlen(p->tmp);

    upper_letter_to_lower(tab);
    sort_letter_alpha(tab, p->tmp);
    len = check_str_len_space(len, tab);
    if ((count_space = count_space_tab(tab, len)) == -1)
        return (false);
    erase_doublon(tab, tab);
    tab = new_tab_without_empty_line(tab);
    str_to_upper(p->tmp);
    if (step == false)
        manage_city_choice(tab, len, p, count_space);
    else
        manage_street_name_choice(tab, len, p, count_space);
    return (true);
}