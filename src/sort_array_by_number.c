/*
** EPITECH PROJECT, 2022
** sort_array_by_number.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

void big_swap(int i, int j, int *nb, char **final)
{
    int tmp_nb = 0;
    char *tmp = NULL;

    if (i != j)
        if (nb[i] > nb[j]) {
            tmp_nb = nb[i];
            nb[i] = nb[j];
            nb[j] = tmp_nb;
            tmp = strdup(final[i]);
            check_malloc_str(tmp);
            final[i] = strdup(final[j]);
            check_malloc_str(final[i]);
            final[j] = strdup(tmp);
            check_malloc_str(final[j]);
        }
    if (tmp != NULL)
        free(tmp);
}

void sort_array_by_number(char **final, char *buffer)
{
    int *nb = count_occurence_for_sort(final, buffer);

    for (int i = 0; nb[i] != -1; ++i) {
        for (int j = 0; nb[j] != -1; ++j)
            big_swap(i, j, nb, final);
    }
    for (int i = 0; nb[i] != -1; ++i)
        if (nb[i + 1] != -1 && nb[i] < nb[i + 1])
            count_occurence_for_sort(final, buffer);
}