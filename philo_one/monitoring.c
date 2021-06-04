#include "philo.h"

void*	monitoring(void* _data)
{
	size_t	index;

	t_data* data = (t_data*)_data;
	while (1)
	{
		index = 0;
		while (data->general->philo_num > index)
		{
			if ((get_current_time(data->philo[index]->ate_last_time)) >= data->general->time_to_die)
			{
				// data->general->stop = 1;
				pthread_mutex_lock(&data->general->talking);
				printf(KRED "%ld %zu died\n" RESET, get_current_time(data->philo[index]->start_time), data->philo[index]->id);
				pthread_mutex_unlock(&data->general->talking);
				exit(0);
			}
			// usleep(100);
			index++;
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
