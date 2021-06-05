#include "philo.h"

t_philosopher	*init_philo(size_t index, t_data *data)
{
	t_philosopher	*philo;

	philo = malloc(sizeof(t_philosopher));
	philo->left_fork = &data->mutex[index];
	if (data->general->philo_num == index + 1)
		philo->right_fork = &data->mutex[0];
	else
		philo->right_fork = &data->mutex[index + 1];
	philo->status = 0;
	philo->is_full = 0;
	philo->ate_last_time = get_current_time(0);
	philo->id = index + 1;
	philo->ate_count = 0;
	return (philo);
}

t_data	*init_data(char **av)
{
	t_data			*data;
	t_general		*general;
	size_t			index;
	t_philosopher	**philo;

	general = parser(av);
	data = malloc(sizeof(t_data));
	philo = malloc(sizeof(t_philosopher *) * general->philo_num);
	data->mutex = malloc(sizeof(pthread_mutex_t) * general->philo_num);
	index = 0;
	data->general = general;
	while (index < general->philo_num)
	{
		philo[index] = init_philo(index, data);
		pthread_mutex_init(&data->mutex[index], NULL);
		philo[index]->general = general;
		index++;
	}
	data->philo = philo;
	return (data);
}
