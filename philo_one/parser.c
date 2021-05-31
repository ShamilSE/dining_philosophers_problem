#include "philo.h"

t_data*	parser(char** av)
{
	t_data*	data;

	data = malloc(sizeof(t_data));
	if (!is_args_digit(av))
		ft_error("invalid arguments");
	data->philo_num = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->hungry = ft_atoi(av[5]);
	return data;
}
