NAME = philoone
SRC = main.c utils/utils.c parser.c lifecycle.c init_data.c monitoring.c die_check.c \
	utils/ft_atoi.c log_philo.c utils/cleaning.c
INC = philo.h

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC) $(INC)
	gcc $(CFLAGS) $(SRC) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re