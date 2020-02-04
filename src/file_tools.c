/*
** EPITECH PROJECT, 2022
** file_tools.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

int check_pos_num(char *str)
{
    int i;

    for (i = 0; str[i] != ','; i++);
    if (str[i + 1] == ' ' && (str[i + 2] >= '0' && str[i + 2] <= '9'))
        return (0);
    return (1);
}

int check_line(char *str)
{
    bool    nb = false;
    bool    comma = false;
    int     space = 0;

    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
        if (comma == true && (str[i] >= '0' && str[i] <= '9'))
            nb = true;
        if (comma == false && (str[i] >= '0' && str[i] <= '9'))
            return (-1);
        if (str[i] == ',')
            comma = true;
        if (str[i] == ' ')
            space++;
    }
    if (nb == false || comma == false || space < 3)
        return (-1);
    else if (check_pos_num(str) != 0)
        return (-1);
    return (0);
}

int count_malloc(char *file)
{
    FILE* fichier = fopen(file, "r+");
    size_t len = 0;
    char *buffer = NULL;
    int i = 0;

    if (fichier == NULL) {
        dprintf(2, "%s", ERROR_ADRESSE);
        exit (ERROR);
    }
    while (getline(&buffer, &len, fichier) != -1) {
        if (check_line(buffer) == 0)
            i++;
    }
    free(buffer);
    fclose(fichier);
    return (i);
}