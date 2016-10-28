NAME = hashmap

CC = gcc

FLAG = -Wall -Wextra -Werror

RM = rm -f

SRC =	main.c \
		array.c \
		array_manager.c \
		chained_list.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : srcs/%.c
	@$(CC) -c $(FLAG) $< -I includes/

$(NAME) : $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@echo "\033[32m[build] --- $(NAME) created\033[0m"

clean :
	@$(RM) $(OBJ)
	@echo "\033[31m[build] --- $(NAME) *.o deleted\033[0m"

fclean : clean
	@$(RM) $(NAME)
	@echo "\033[31m[build] --- $(NAME) bin deleted\033[0m"

re : fclean all
