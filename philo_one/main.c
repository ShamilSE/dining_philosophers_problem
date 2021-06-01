#include "philo.h"

pthread_mutex_t	mutex;

void*	lifecycle(void*	philosopher)
{
	(void)philosopher;
	return (NULL);
}

void	multithread(t_data* data)
{
	// for (size_t i = 0; i < 20; i++) {
	// 	printf("%s\n", string);
	// 	usleep(10000);
	// }
	size_t	index;

	index = 0;
	while (data->general->philo_num > index)
	{
		pthread_create(&data->philo[index]->thread, NULL, lifecycle, (void*)data->philo[index]);
		pthread_join(data->philo[index]->thread, NULL);
		index++;
	}
}

t_data*	init_data(char** av)
{
	// pthread_t thread1, thread2;
	t_data*		data;
	t_general*	general;
	size_t			index;
	t_philosopher**	philo;

	data = malloc(sizeof(t_data));
	general = parser(av);
	philo = malloc(sizeof(t_philosopher*));
	index = 0;
	while (index < general->philo_num)
	{
		philo[index] = malloc(sizeof(t_philosopher*));
		philo[index]->fork1 = index;
		if (general->philo_num == index + 1)
			philo[index]->fork2 = 0;
		else
			philo[index]->fork2 = index + 1;
		// printf("philo: %zu\nfork1 : %zu\nfork2: %zu\n------------------\n", index, philo[index]->fork1, philo[index]->fork2);
		// pthread_create(&thread1, NULL, lifecycle, (void*)philo[index]);
		index++;
	}
	pthread_mutex_init(&mutex, NULL);
	// pthread_create(&thread2, NULL, hello_world, (void*)string2);

	// pthread_join(thread1, NULL);
	// pthread_join(thread2, NULL);

	// phtread_detach(); - when you dont give a duck about thread clean
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
