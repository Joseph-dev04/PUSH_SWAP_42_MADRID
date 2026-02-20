# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/20 15:32:45 by jopajuel          #+#    #+#              #
#    Updated: 2026/02/20 18:45:11 by aitorres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN := \033[0;32m

RED := \033[31m


NAME = push_swap

SRC = 	main.c\
		error.c\
		parse.c\
		push.c\
		quicksort.c\
		struct_utils.c\
		simple.c\
		medium.c\
		medium_utils.c\
		complex_utils.c\
		complex.c\
		reverse_reverse.c\
		reverse.c\
		swap.c\
		utils.c\
		adaptative.c\
		benchmark.c\
		benchmark_utils.c

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all	: $(NAME)

$(NAME) : $(OBJ)
			@$(CC) $(OBJ) -o $(NAME)
			@echo "${GREEN} $(NAME) creado."

%.o : %.c
		@$(CC) $(FLAGS) -c $< -o $@
clean :
		@$(RM) $(OBJ)
		@echo "${RED} Objetos eliminados."
fclean: clean 
		@$(RM) $(NAME)
		@echo "${RED} Librería eliminada."
re: fclean all

.PHONY: all clean fclean re