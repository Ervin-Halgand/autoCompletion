/*
** EPITECH PROJECT, 2022
** sort_array_by_letter.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

void swap_array_by_letter(char **display, int i, int j, int l)
{
    char *tmp = NULL;

    if (i != j)
        if (display[i][l] < display[j][l]) {
            tmp = strdup(display[i]);
            check_malloc_str(tmp);
            display[i] = strdup(display[j]);
            check_malloc_str(display[i]);
            display[j] = strdup(tmp);
            check_malloc_str(display[j]);
        }
    if (tmp != NULL)
        free(tmp);
}

void sort_letter_alpha(char **display, char *buffer)
{
    int l = strlen(buffer);

    for (int i = 0; display[i]; ++i) {
        for (int j = 0; display[j]; ++j)
            swap_array_by_letter(display, i, j, l);
    }
    for (int i = 0; display[i]; ++i)
        if (display[i + 1] && display[i][l] > display[i + 1][l])
            sort_letter_alpha(display, buffer);
}