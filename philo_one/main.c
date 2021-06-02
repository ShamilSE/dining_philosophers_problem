#include "philo.h"

void	multithread(t_data* data)
{
	size_t	index;

	// for (size_t i = 0; i < 4; i++) {
	// 	printf("philo: %zu\nfork1 : %zu\nfork2: %zu\n------------------\n", i, data->philo[i]->fork1, data->philo[i]->fork2);
	// }
	// pthread_mutex_init(&mutex, NULL);
	index = 0;
	while (data->general->philo_num > index)
	{
		data->index = index;
		pthread_create(&data->philo[index]->thread, NULL, lifecycle, (void*)data);
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
}

int	main(int ac, char** av)
{
	// struct	timeval tv;
	t_data*	data;

	if (ac != 6 && ac !=5)
		ft_error("invalid argument count\n");
	if (ac == 5)
		av[5] = NULL;
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
