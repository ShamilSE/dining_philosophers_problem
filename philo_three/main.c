#include "philo.h"

int	multithread(t_data *data)
{
	size_t		index;
	
	// pthread_t	ate_monitor;
	index = 0;
	while (data->general->philo_num > index)
	{
		data->philo[index]->start_time = get_current_time(0);
		printf("index %zu hello\n", index);
		data->pid[index] = fork();
		if (data->pid == 0)
		{
			lifecycle(data->philo[index]);
		}
		index++;
	}
	// pthread_create(&ate_monitor, NULL, ate_monitoring, (void *)data);
	// pthread_detach(ate_monitor);
	sem_wait(data->general->death);
	return (SUCCESS_CODE);
}

int	main(int ac, char **av)
{
	t_data	*data;
	size_t	index;

	if (ac != 6 && ac != 5)
		ft_error("invalid argument count");
	if (ac == 5)
		av[5] = NULL;
	data = init_data(av);
	if (multithread(data) == 1)
		return (FAIL_CODE);
	cleaning(data);
	index = 0;
	while (index < data->general->philo_num)
	{
		kill(data->pid[index], SIGTERM);
	}
	return (SUCCESS_CODE);
}
