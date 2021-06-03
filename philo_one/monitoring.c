#include "philo.h"

void*	monitoring(void* _data)
{
	size_t	index;
	// t_data*	data;

	// data = NULL;
	t_data* data = (t_data*)_data;
	while (1)
	{
		// if (data->general->hungry)
		// {}
		index = 0;
		while (data->general->philo_num < index)
		{
			if ((get_current_time(0) - data->philo[index]->ate_last_time) > data->general->time_to_die)
			{
				printf(KRED "%ld %zu died" RESET, get_current_time(data->philo[index]->start_time), data->philo[index]->id);
				exit(0);
			}
			index++;
		}
		usleep(1000);
	}
}
