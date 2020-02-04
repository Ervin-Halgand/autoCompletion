/*
** EPITECH PROJECT, 2022
** autocompletion.h
** File description:
** Created by Ervin,
*/

#ifndef RATTRAPAGE_AUTOCOMPLETION_H
#define RATTRAPAGE_AUTOCOMPLETION_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define ERROR (84)
#define SUCCESS (0)
#define ERROR_ARG "Invalid argument\0"
#define ERROR_ADRESSE "Unknown address\0"

typedef struct s_autocompletion
{
    char **dictionary;
    char **city;
    char **number;
    char **street_type;
    char **street_name;
    char *buffer;
    char *tmp;
    int len;
} t_parsing;

typedef struct s_increment
{
    int x;
    int y;
} t_increment;

void check_malloc_str(char *);
int check_line(char *);
int count_malloc(char *);
char **get_city(char **);
char **get_number(char **);
char **get_street_type(char **);
char **fill_street_type_tab();
char **get_street_name(char **);
char **get_file(char *);
char **erase_unsed(char **, t_parsing, int *, int);
char **tab_to_display(int, t_parsing *, int *, char **);
char **cpy_tab(char **);
char **parse_space_city(char **);
int count_new_buffer(char **, char *);
int count_new_buffer(char **, char *);
void display_more_occurence(t_parsing);
void count_all_letter(t_parsing, int **);
void free_city(char **, char **);
void erase_doublon(char **, char **);
char *check_street_name(t_parsing *, char *, bool *, int *);
char *city_find(char **);
char *city_find(char **);
char *check_city(t_parsing *, bool *, int, int *);
bool second_shoot(char **, int, t_parsing, bool *);
bool one_shot_all(t_parsing, int, bool *);
bool cmp_non_sensitive_char(char, char);
bool new_buffer(t_parsing *);
char *unknown_adress(int *, bool *);
void init_buffer(t_parsing *);
char **display_adresse(char **, t_parsing *, bool *, bool);
char **new_tab_without_empty_line(char **);
void upper_letter_to_lower(char **);
void lower_letter_to_upper(char **);
void sort_letter_alpha(char **,  char *);
int *count_occurence_for_sort(char **, char *);
char **parse_tab_to_match_to_buffer(int check, t_parsing *p, char **display);
t_parsing init_parsing(char *);
void check_arg(int, char **);
void free_all(t_parsing);
bool manage_space(t_parsing *, char **, bool);
void sort_array_by_number(char **, char *);
char *str_to_upper(char *str);
char **erase_special_char(char **);
void get_all_street_name_equal(t_parsing p, char **test);
int count_nb_line_tab(char **);
char **malloc_tab_whith_line_defined(int);
void fill_line_tab(char **, char *, int);
void check_all_street_name_equal(char **, t_parsing);
int *get_occurence(char **, char *);
char **get_matched_to_buffer_first_time(char **, int *);
char **get_matched_to_buffer(char **, t_parsing, int *);
void display_final_choice(char **, char **, int, t_parsing);
void display_choices_city(t_parsing, int, int, char **);
void manage_street_name_choice(char **tab, int len, t_parsing *p, \
int count_space);
int count_space_tab(char **, int);
void display_space_choice(int *);

#endif
