#include "philo.h"


void	multithread(t_data* data)
{
	pthread_mutex_t	mutex;
	size_t	index;

	// for (size_t i = 0; i < 4; i++) {
	// 	printf("philo: %zu\nfork1 : %zu\nfork2: %zu\n------------------\n", i, data->philo[i]->fork1, data->philo[i]->fork2);
	// }
	pthread_mutex_init(&mutex, NULL);
	// while (1)
	// {
		index = 0;
		while (data->general->philo_num > index)
		{
			printf("index: %zu\n", index);

			pthread_create(&data->philo[index]->thread, NULL, lifecycle, (void*)data->philo[index]);
			// pthread_detach(data->philo[index]->thread);
			// pthread_mutex_lock(&mutex);
			index++;
			// pthread_mutex_unlock(&mutex);
		}
		index = 0;
		while (data->general->philo_num > index)
		{
			pthread_join(data->philo[index]->thread, NULL);
			index++;
		}
	// }
}

t_data*	init_data(char** av)
{
	t_data*		data;
	t_general*	general;
	size_t			index;
	t_philosopher**	philo;

	data = malloc(sizeof(t_data));
	general = parser(av);
	philo = malloc(sizeof(t_philosopher*) * general->philo_num);
	index = 0;
	while (index < general->philo_num)
	{
		philo[index] = malloc(sizeof(t_philosopher));
		philo[index]->fork1 = index;
		if (general->philo_num == index + 1)
			philo[index]->fork2 = 0;
		else
			philo[index]->fork2 = index + 1;
		index++;
	}
	data->general = general;
	data->philo = philo;
	return (data);
}

int	main(int ac, char** av)
{
	// struct	timeval tv;
	t_data*	data;

	if (ac != 6)
		ft_error("invalid argument count\n");
	data = init_data(av);
	multithread(data);
	// while (1) {
	// 	usleep(1000000);
	// 	gettimeofday(&tv, NULL);
	// 	printf("%ld\n", tv.tv_sec);
	// }
	free(data);
	return (0);
}
