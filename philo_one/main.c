#include "philo.h"

int	multithread(t_data *data)
{
	size_t		index;
	pthread_t	monitor;

	index = 0;
	while (data->general->philo_num > index)
	{
		data->philo[index]->start_time = get_current_time(0);
		if (pthread_create(&data->philo[index]->thread, NULL,
				lifecycle, (void *)data->philo[index]) != 0)
			return (FAIL_CODE);
		usleep(100);
		index++;
	}
	if (pthread_create(&monitor,
			NULL, monitoring, (void *)data) != 0)
		return (FAIL_CODE);
	pthread_join(monitor, NULL);
	return (SUCCESS_CODE);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 6 && ac !=5)
		ft_error("invalid argument count");
	if (ac == 5)
		av[5] = NULL;
	data = init_data(av);
	if (multithread(data) == 1)
		return (FAIL_CODE);
	cleaning(data);
	return (SUCCESS_CODE);
}
