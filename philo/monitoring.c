#include "philo.h"

static int	is_dead(t_data *data)
{
	size_t	index;

	index = 0;
	while (index < data->general->philo_num)
	{
		pthread_mutex_lock(&data->general->time);
		if ((get_current_time(data->philo[index]->ate_last_time))
			> data->philo[index]->general->time_to_die)
		{
			pthread_mutex_lock(&data->philo[index]->general->talking);
			log_philo(KRED "died" RESET, data->philo[index]);
			data->general->everybody_alive = 0;
			return (1);
		}
		pthread_mutex_unlock(&data->general->time);
		index++;
	}
	return (0);
}

static int	is_full(t_data *data)
{
	if (data->general->fulls == data->general->philo_num)
	{
		pthread_mutex_lock(&data->general->talking);
		printf(KGRN "everybody ate %zu times\n"
			RESET, data->general->hungry);
		data->general->everybody_alive = 0;
		return (1);
	}
	return (0);
}

void	*monitoring(void *_data)
{
	t_data	*data;

	data = (t_data *)_data;
	while (1)
	{
		if (is_full(data))
			return (NULL);
		if (is_dead(data))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
