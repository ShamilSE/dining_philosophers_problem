#include "../philo.h"

int		is_args_digit(char** av)
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
			{
				ft_putchar_fd(av[i][ii], 1);
				return (0);
			}
			ii++;
		}
		i++;
	}
	return (1);
}

void	ft_error(char* msg)
{
	ft_putstr_fd(msg, 0);
	exit(0);
}

long	get_current_time(long start_time)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL); 
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - start_time);
}
