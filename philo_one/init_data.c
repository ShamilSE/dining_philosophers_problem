#include "philo.h"

t_data*	init_data(char** av)
{
	t_data*		data;
	t_general*	general;
	size_t			index;
	t_philosopher**	philo;

	data = malloc(sizeof(t_data));
	general = parser(av);
	philo = malloc(sizeof(t_philosopher*) * general->philo_num);
	index = 0;
	while (index < general->philo_num)
	{
		philo[index] = malloc(sizeof(t_philosopher));
		philo[index]->fork1 = index;
		if (general->philo_num == index + 1)
			philo[index]->fork2 = 0;
		else
			philo[index]->fork2 = index + 1;
		index++;
	}
	data->general = general;
	data->philo = philo;
	return (data);
}
