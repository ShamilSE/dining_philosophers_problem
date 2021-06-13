#include "../philo.h"

void	cleaning(t_data *data)
{
	size_t	index;

	index = 0;
	if (data->general->philo_num == 1)
		pthread_mutex_unlock(&data->mutex[0]);
	while (data->general->philo_num > index)
	{
		pthread_join(data->philo[index]->thread, NULL);
		pthread_mutex_destroy(&data->mutex[index]);
		free(data->philo[index]);
		index++;
	}
	pthread_mutex_destroy(&data->general->talking);
	pthread_mutex_destroy(&data->general->time);
	free(data->philo);
	free(data->mutex);
	free(data->general);
	free(data);
}
