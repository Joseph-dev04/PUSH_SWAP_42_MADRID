# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/20 15:32:45 by jopajuel          #+#    #+#              #
#    Updated: 2026/02/20 15:35:31 by jopajuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN := \033[0;32m

RED := \033[31m


NAME = push_swap

SRC = error.c intermedio.c main.c parse.c push.c quicksort.c radix_utils.c radix.c reverse_reverse.c reverse.c simple.c struct_utils.c swap.c utils.c\
		 adaptative.c intermedio_utils.c benchmark.c benchmark_utils.c

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