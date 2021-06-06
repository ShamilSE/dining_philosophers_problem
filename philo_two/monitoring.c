#include "philo.h"

void	*monitoring(void *_data)
{
	t_data	*data;
	size_t	index;

	index = 0;
	data = (t_data *)_data;
	while (1)
	{
		if (data->general->fulls == data->general->philo_num)
		{
			// pthread_mutex_lock(&data->general->talking);
			sem_wait(data->general->talking);
			printf(KGRN "everybody ate %zu times\n"
				RESET, data->general->hungry);
			data->general->stop_flag = 1;
			break ;
		}
		index = 0;
		while (index < data->general->philo_num)
		{
			// sem_wait(data->general->time);
			if ((get_current_time(data->philo[index]->ate_last_time))
				> data->philo[index]->general->time_to_die + 3)
			{
				sem_wait(data->general->talking);
				log_philo(KRED "died" RESET, data->philo[index]);
				data->philo[index]->general->stop_flag = 1;
				return (NULL);
			}
			// sem_post(data->general->talking);
			index++;
		}
		usleep(1000);
	}
	return (NULL);
}
