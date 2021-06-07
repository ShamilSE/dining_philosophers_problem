NAME = philo_two
SRC = main.c utils/utils.c parser.c lifecycle.c init_data.c monitoring.c \
	utils/ft_atoi.c log_philo.c utils/cleaning.c
INC = philo.h

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC) $(INC)
	gcc $(CFLAGS) $(SRC) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all

test1:
	./$(NAME) 5 800 200 200

test2:
	./$(NAME) 5 800 200 200 7

test3:
	./$(NAME) 4 410 200 200

test4:
	./$(NAME) 4 310 200 100

.PHONY: all clean fclean re test1 test2 test3 test4