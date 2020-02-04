/*
** EPITECH PROJECT, 2022
** tools_lower_uppercase.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

char *str_to_upper(char *str)
{
    for (int j = 0; str[j]; ++j) {
        if (isalpha(str[j]) && !isupper(str[j]))
            str[j] -= 32;
    }
    return (str);
}

void swapping_lower_to_upper(char **display, int i, int l)
{
    for (int j = 0; display[i][j]; ++j) {
        if (!isupper(display[i][j]) && j < l && display[i][j] != ' ')
            display[i][j] -= 32;
    }
}

void lower_letter_to_upper(char **display)
{
    int l = 0;

    while (display[0][l])
        l++;
    l--;
    for (int i = 0; display[i]; ++i)
        swapping_lower_to_upper(display, i, l);
}

void swaping_upper_letter_to_lower(char **display, int i)
{
    for (int j = 0; display[i][j]; ++j) {
        if (isupper(display[i][j]))
            display[i][j] += 32;
    }
}

void upper_letter_to_lower(char **display)
{
    for (int i = 0; display[i]; ++i)
        swaping_upper_letter_to_lower(display, i);
}