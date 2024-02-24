NAME := philo

CFLAGS := -Wall -Wextra -Werror -Iinclude
CC := clang

SRC := src/main.c \
		src/parsing.c \
		src/utils/ft_atoul.c
OBJ := $(SRC:.c=.o)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $(NAME) -lpthread -Llib -lft

all:		$(NAME)

clean:
			$(RM) -f $(OBJ)

fclean:		clean
			$(RM) -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

