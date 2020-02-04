/*
** EPITECH PROJECT, 2022
** city_to_display.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

void city_not_found_new_choice(char **final)
{
    int count = 0;

    for (int i = 0; final[i]; ++i) {
        if (final[i][0] != '\0')
            count++;
    }
    if (count > 5)
        count = 5;
    for (int j = 0; j < count; ++j) {
        printf("{%s}", final[j]);
        if (j + 1 < count)
            printf(" ");
    }
    for (int k = 0; final[k]; ++k)
        free(final[k]);
    free(final);
    printf("\n");
}

char **display_adresse(char **display, t_parsing *p, bool *dont_display,
    bool step)
{
    int check = 0;
    char **test = cpy_tab(display);

    for (int i = 0; display[i]; ++i)
        check++;
    display = erase_special_char(display);
    if (step == true)
        check_all_street_name_equal(display, *p);
    display = parse_tab_to_match_to_buffer(check, p, display);
    upper_letter_to_lower(display);
    sort_letter_alpha(display, p->tmp);
    if (check > 2)
        sort_array_by_number(display, p->tmp);
    erase_doublon(display, display);
    lower_letter_to_upper(display);
    if (manage_space(p, test, step) == false)
        *dont_display = true;
    display = new_tab_without_empty_line(display);
    return (display);
}

char *manage_autocompletion_step(char **display, char **tmp,
    char *city, t_parsing *p)
{
    bool dont_display = false;

    display = cpy_tab(tmp);
    display = new_tab_without_empty_line(display);
    if ((city = city_find(display)) != NULL) {
        free_city(display, tmp);
        return (city);
    }
    display = display_adresse(display, p, &dont_display, false);
    city_not_found_new_choice(display);
    return (NULL);
}

char *check_city(t_parsing *p, bool *finish, int len, int *error)
{
    char **tmp = cpy_tab(p->city);
    char **display = NULL;
    char *city = NULL;
    int counter = 0;

    for (int i = 0; p->city[i]; ++i) {
        if (one_shot_all(*p, i, finish) == true)
            return (NULL);
    }
    tmp = parse_space_city(tmp);
    tmp = erase_unsed(tmp, *p, &counter, len);
    if (second_shoot(tmp, counter, *p, finish) == true)
        return (NULL);
    if (counter == 0)
        return (unknown_adress(error, finish));
    if ((city = manage_autocompletion_step(display, tmp, city, p)) != NULL)
        return (city);
    return (NULL);
}