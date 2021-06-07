#include "philo.h"

static int	is_dead(t_data *data)
{
	size_t	index;

	index = 0;
	while (index < data->general->philo_num)
	{
		sem_wait(data->general->time);
		if ((get_current_time(data->philo[index]->ate_last_time))
			> data->philo[index]->general->time_to_die + 3)
		{
			sem_wait(data->general->talking);
			printf(KRED "%zu %zu died\n" RESET,
				get_current_time(data->philo[index]->start_time),
				data->philo[index]->id);
			return (1);
		}
		sem_post(data->general->time);
		index++;
	}
	return (0);
}

static int	is_full(t_data *data)
{
	if (data->general->fulls == data->general->philo_num)
	{
		sem_wait(data->general->talking);
		printf(KGRN "everybody ate %zu times\n"
			RESET, data->general->hungry);
		return (1);
	}
	return (0);
}

void	*monitoring(void *_data)
{
	t_data	*data;
	size_t	index;

	index = 0;
	data = (t_data *)_data;
	while (1)
	{
		if (is_full(data))
			return (NULL);
		index = 0;
		if (is_dead(data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
