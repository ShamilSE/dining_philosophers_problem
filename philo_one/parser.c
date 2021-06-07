#include "philo.h"

t_general	*parser(char **av)
{
	t_general	*general;

	general = malloc(sizeof(t_general));
	if (!is_args_digit(av))
		ft_error("invalid arguments");
	general->philo_num = ft_atoi(av[1]);
	general->time_to_die = ft_atoi(av[2]);
	general->time_to_eat = ft_atoi(av[3]);
	general->time_to_sleep = ft_atoi(av[4]);
	general->fulls = 0;
	if (av[5] != NULL)
		general->hungry = ft_atoi(av[5]);
	else
		general->hungry = 0;
	return (general);
}
