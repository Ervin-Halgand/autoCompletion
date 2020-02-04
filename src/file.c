/*
** EPITECH PROJECT, 2022
** file.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

void erase_backslash_n(char **content)
{
    for (int j = 0; content[0][j]; ++j) {
        if (content[0][j] == '\n') {
            content[0][j] = '\0';
            break;
        }
    }
}

void fill_file_content(char **content, FILE* fichier)
{
    int i = 0;
    size_t len = 0;
    char *buffer = NULL;

    while (getline(&buffer, &len, fichier) != -1) {
        if (check_line(buffer) == 0)
            check_malloc_str(content[i++] = strdup(buffer));
        else
            dprintf(2, "%s", buffer);
    }
    free(buffer);
    if (i == 1) {
        erase_backslash_n(content);
        printf("=> %s\n", content[0]);
        exit (0);
    }
}

char **get_file(char *file)
{
    FILE* fichier = fopen(file, "r");
    char **content = NULL;
    int i = 0;

    if (!fichier) {
        dprintf(2, "error file not found");
        exit(84);
    }
    i = count_malloc(file);
    if (!(content = calloc(sizeof(char*), i + 1)))
        exit (84);
    content[i] = NULL;
    fill_file_content(content, fichier);
    fclose(fichier);
    return (content);
}