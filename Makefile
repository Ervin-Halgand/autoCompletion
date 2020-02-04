##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	src/autocompletion.c				\
		src/parse_city.c					\
		src/parse_number.c					\
		src/parse_street_type.c				\
		src/parse_street_name.c				\
		src/file.c							\
		src/city_to_display.c				\
		src/tools.c							\
		src/display_street_type.c			\
		src/finding_city.c					\
		src/clean_array.c					\
		src/finish.c						\
		src/manage_buffer.c					\
		src/project_init.c					\
		src/manage_space.c					\
		src/sort_array_by_number.c			\
		src/sort_array_by_letter.c			\
		src/tools_lower_uppercase.c			\
		src/file_tools.c					\
		src/malloc.c						\
		src/tools_array.c					\
		src/street_name_equal.c				\
		src/occurrence_letter.c				\
		src/street_name_tools.c				\
		src/display_choice_street_type.c	\
		src/display_choice_city.c

NAME	=	autoCompletion

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

RM	=	rm -f

INC	=	-I include/

CFLAGS	=	$(INC) -W -Wall -Wextra

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

debug: 		CFLAGS += -g
debug:		re