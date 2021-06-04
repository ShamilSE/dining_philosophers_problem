#include "philo.h"

void	init_philo(t_philosopher **philo, size_t index)
{
	philo[index]->status = 0;
	philo[index]->is_full = 0;
	philo[index]->ate_last_time = get_current_time(0);
	philo[index]->id = index + 1;
}

t_data	*init_data(char **av)
{
	t_data			*data;
	t_general		*general;
	size_t			index;
	t_philosopher	**philo;

	general = parser(av);
	data = malloc(sizeof(t_data));
	philo = malloc(sizeof(t_philosopher*) * general->philo_num);
	data->mutex = malloc(sizeof(pthread_mutex_t) * general->philo_num);
	index = 0;
	general->stop = 0;
	while (index < general->philo_num)
	{
		philo[index] = malloc(sizeof(t_philosopher));
		pthread_mutex_init(&data->mutex[index], NULL);
		init_philo(philo, index);
		philo[index]->left_fork = &data->mutex[index];
		if (general->philo_num == index + 1)
			philo[index]->right_fork = &data->mutex[0];
		else
			philo[index]->right_fork = &data->mutex[index + 1];
		philo[index]->general = general;
		index++;
	}
	data->general = general;
	data->philo = philo;
	return (data);
}
