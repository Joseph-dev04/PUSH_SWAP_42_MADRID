# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/20 15:32:45 by jopajuel          #+#    #+#              #
#    Updated: 2026/02/25 13:23:40 by aitorres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN := \033[0;32m
RED := \033[31m

NAME = push_swap
NAME_BONUS = checker

CC = cc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror

DIR = bonus
OBJ_DIR = obj

SRC = main.c \
	error.c \
	parse.c \
	parse_utils.c\
	push.c \
	quicksort.c \
	struct_utils.c \
	simple.c \
	medium.c \
	medium_utils.c \
	complex_utils.c \
	complex.c \
	comple_utils2.c \
	reverse_reverse.c \
	reverse.c \
	swap.c \
	utils.c \
	adaptive.c \
	benchmark.c \
	benchmark_utils.c

SRC_BONUS = $(DIR)/get_num_bonus.c \
	$(DIR)/struct_utils_bonus.c \
	$(DIR)/utils_bonus.c \
	$(DIR)/check_push_bonus.c \
	$(DIR)/check_reverse_bonus.c \
	$(DIR)/check_rreverse_bonus.c \
	$(DIR)/check_swap_bonus.c \
	$(DIR)/checker_bonus.c \
	$(DIR)/error_bonus.c \
	$(DIR)/get_next_line_bonus.c \
	$(DIR)/get_next_line_utils_bonus.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(SRC_BONUS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) creado."

$(NAME_BONUS): $(OBJ_BONUS)
	@$(CC) $(FLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)
	@echo "$(GREEN)$(NAME_BONUS) creado."

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)Objetos eliminados."

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(RED)Ejecutadores eliminados."

re: fclean all

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re bonus
