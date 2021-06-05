#include "philo.h"

void	*ate_monitoring(void *_data)
{
	size_t	index;
	t_data	*data;

	data = (t_data *)_data;
	while (!data->general->stop_flag)
	{
		index = 0;
		if (data->general->fulls == data->general->philo_num)
		{
			pthread_mutex_lock(&data->general->talking);
			printf(KGRN "everybody ate %zu times\n"
				RESET, data->general->hungry);
			data->general->stop_flag = 1;
			pthread_mutex_unlock(&data->general->talking);
			break ;
		}
	}
	return (NULL);
}
