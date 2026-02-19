


NAME = push_swap

SRC = error.c intermedio.c main.c parse.c push.c quicksort.c radix_utils.c radix.c reverse_reverse.c reverse.c simple.c struct_utils.c swap.c utils.c\
		 adaptative.c intermedio_utils.c benchmark.c

CC = cc

RM = rm

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all	: $(NAME)

$(NAME) : $(OBJ)
			@$(CC) $(OBJ) -o $(NAME)

%.o : %.c
		@$(CC) $(FLAGS) -c $< -o $@
clean :
		@$(RM) $(OBJ)
fclean: clean 
		@$(RM) -f $(NAME)
re: all