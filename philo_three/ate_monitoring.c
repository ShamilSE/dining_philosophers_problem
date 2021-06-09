#include "philo.h"

void	*ate_monitoring(void *_data)
{
	size_t	index;
	t_data	*data;

	data = (t_data *)_data;
	index = 0;
	while (data->general->philo_num > index)
	{
		sem_wait(data->general->full);
		index++;
	}
	sem_wait(data->general->talking);
	printf(KGRN "everybody ate %zu times\n"
		RESET, data->general->hungry);
	sem_post(data->general->death);
	exit(2);
	return (0);
}
