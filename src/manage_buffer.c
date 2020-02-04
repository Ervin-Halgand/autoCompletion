/*
** EPITECH PROJECT, 2022
** manage_buffer.c
** File description:
** Created by Ervin,
*/

#include "../include/autocompletion.h"

char *check_buffer(char *buffer)
{
    for (int i = 0; buffer[i]; ++i)
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            break;
        }
    return (buffer);
}

void check_equal(bool *check, char **tmp, int k, int len)
{
    for (int i = 0; tmp[i]; ++i) {
        if (i == k)
            continue;
        if (strncasecmp(tmp[k], tmp[i], len))
            *check = true;
    }
}

int count_new_buffer(char **tmp, char *str)
{
    bool check = false;
    int len = strlen(str);

    for (int k = 0; tmp[k]; ++k) {
        check_equal(&check, tmp, k, len);
        if (check == false)
            len++;
        if (!tmp[k + 1] && check == false)
            k = 0;
    }
    len--;
    return (len);
}

void init_buffer(t_parsing *parsing)
{
    parsing->buffer = calloc(sizeof(char), 1);
    check_malloc_str(parsing->buffer);
    parsing->buffer[0] = '\0';
    parsing->tmp = calloc(sizeof(char), 1);
    check_malloc_str(parsing->tmp);
    parsing->tmp[0] = '\0';
    parsing->len = strlen(parsing->tmp);
}

bool new_buffer(t_parsing *pars)
{
    size_t size = 0;

    while (getline(&pars->buffer, &size, stdin)) {
        check_buffer(pars->buffer);
        if (!strcasecmp(pars->buffer, "abort") || strlen(pars->buffer) <= 1)
            break;
    }
    if (!strcasecmp(pars->buffer, "abort")) {
        pars->len = -1;
        exit(0);
    }
    pars->len = strlen(pars->tmp);
    pars->tmp = realloc(pars->tmp,sizeof(char) * (pars->len + 2));
    check_malloc_str(pars->tmp);
    pars->tmp[pars->len] = pars->buffer[0];
    pars->tmp[pars->len + 1] = '\0';
    pars->len = strlen(pars->tmp);
    return (true);
}