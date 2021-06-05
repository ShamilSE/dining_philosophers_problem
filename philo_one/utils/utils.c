#include "../philo.h"

int	is_args_digit(char **av)
{
	size_t	i;
	size_t	ii;

	i = 1;
	while (av[i])
	{
		ii = 0;
		while (av[i][ii])
		{
			if (!ft_isdigit(av[i][ii]) && av[i][ii] != ' ')
				return (0);
			ii++;
		}
		i++;
	}
	return (1);
}

void	ft_error(char *msg)
{
	printf("%s\n", msg);
	exit(0);
}

long	get_current_time(long start_time)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - start_time);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c < 58);
}
