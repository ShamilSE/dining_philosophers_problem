#include "philo.h"

int		multithread(t_data *data)
{
	size_t	index;

	index = 0;
	while (data->general->philo_num > index)
	{
		data->philo[index]->start_time = get_current_time(0);
		if (pthread_create(&data->philo[index]->thread, NULL,
			lifecycle, (void *)data->philo[index]) != 0)
			return (FAIL_CODE);
		index++;
	}
	if (pthread_create(&data->ate_monitoring, NULL, monitoring, (void *)data) != 0)
		return (FAIL_CODE);
	pthread_join(data->ate_monitoring, NULL);
	index = 0;
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
	// cleaning(data);
	// sem_unlink("talking");
	// sem_unlink("time");
	// sem_unlink("forks");
	// sem_close(data->general->forks);
	// sem_close(data->general->time);
	// sem_close(data->general->talking);
	return (SUCCESS_CODE);
}
