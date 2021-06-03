#include "philo.h"

void	multithread(t_data* data)
{
	size_t	index;

	
	index = 0;
	while (data->general->philo_num > index)
	{
		pthread_create(&data->philo[index]->thread, NULL, lifecycle, (void*)data->philo[index]);
		// if (data->philo[index]->id % 2 != 0)
		// 	usleep(100);
		index++;
	}
	index = 0;
	while (data->general->philo_num > index)
	{
		pthread_join(data->philo[index]->thread, NULL);
		index++;
	}
}

int	main(int ac, char** av)
{
	t_data*	data;

	if (ac != 6 && ac !=5)
		ft_error("invalid argument count\n");
	if (ac == 5)
		av[5] = NULL;
	data = init_data(av);
	multithread(data);
	// free(data);
	return (0);
}
