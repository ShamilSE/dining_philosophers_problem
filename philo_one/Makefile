NAME = a.out
SRC = main.c utils/utils.c parser.c lifecycle.c
INC = philo.h

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

all: $(NAME)

$(NAME): $(SRC) $(INC)
	make -C ../ftlib
	gcc $(CFLAGS) $(SRC) ../ftlib/ftlib.a -o $(NAME)

clean:
	make clean -C ../libft

fclean:
	make fclean -C ../ftlib
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re