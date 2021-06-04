#include "philo.h"

void	is_smd_died(t_data *data, size_t index)
{
	if ((get_current_time(0) - data->philo[index]->ate_last_time) > data->general->time_to_die)
	{
		data->general->stop = 1;
		pthread_mutex_lock(&data->general->talking);
		printf(KRED "%ld %zu died\n" RESET, get_current_time(data->philo[index]->start_time), data->philo[index]->id);
		pthread_mutex_unlock(&data->general->talking);
		exit(0);
	}
}

int		all_full(t_data *data)
{
	size_t	index;

	index = 0;
	while (data->general->philo_num > index)
	{
		if (data->philo[index]->is_full != 1)
			return (0);
		index++;
	}
	return (1);
}

void*	monitoring(void* _data)
{
	size_t	index;

	t_data* data = (t_data*)_data;
	while (1)
	{
		index = 0;
		while (data->general->philo_num > index)
		{
			is_smd_died(data, index);
			index++;
		}
		if (all_full(data))	
		{
			printf(KGRN "everybody is full\n" RESET);
			exit(0);
		}

		// while (ii < data->general->philo_num)
		// {
		// 	if (data->general->hungry && data->philo[ii]->ate_count >= data->general->hungry)
		// 		ii++;
		// 	if (ii == data->general->philo_num)
		// 	{
		// 		pthread_mutex_lock(&data->general->talking);
		// 		printf(KGRN "everybody is full\n" RESET);
		// 		pthread_mutex_unlock(&data->general->talking);
		// 		exit(0);
		// 	}
		// }
	}
}
