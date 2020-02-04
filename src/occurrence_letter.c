/*
** EPITECH PROJECT, 2022
** occurrence_letter.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

void count_equal(char **display, int i, int l, int *count)
{
    for (int j = 0; display[j]; ++j) {
        if (i == j)
            continue;
        if (display[i][l] == display[j][l])
            (*count)++;
    }
}

int *count_occurence_for_sort(char **display, char *buffer)
{
    int l = strlen(buffer);
    int count = 0;
    int incr2 = 0;
    int *test;
    int malloc = count_nb_line_tab(display);
    int i;

    if ((test = calloc(sizeof(int), malloc + 1)) == NULL)
        exit (84);
    test[malloc] = -1;
    for (i = 0; display[i]; ++i) {
        count_equal(display, i, l, &count);
        if (incr2 != 0 && count == test[incr2 - 1])
            test[incr2] = test[incr2 - 1] + 1;
        else
            test[incr2] = count;
        incr2++;
        count = 0;
    }
    return (test);
}

int count_malloc_occurence(char *city, char **all_city)
{
    int malloc = 0;

    for (int i = 0; all_city[i]; ++i)
        for (int k = 0; all_city[i][k]; ++k) {
            if (!strncasecmp(city, &all_city[i][k], strlen(city))) {
                malloc++;
                break;
            }
        }
    return (malloc);
}

int *get_occurence(char **all_city, char *city)
{
    int malloc = count_malloc_occurence(city, all_city);
    int *number = NULL;
    int j = 0;

    if (malloc == 0)
        return (NULL);
    number = calloc(sizeof(int), malloc + 1);
    if (number == NULL)
        return (NULL);
    number[malloc] = -1;
    for (int i = 0; all_city[i]; ++i) {
        for (int k = 0; all_city[i][k]; ++k) {
            if (!strncasecmp(city, &all_city[i][k], strlen(city))) {
                number[j] = i;
                j++;
                break;
            }
        }
    }
    return (number);
}