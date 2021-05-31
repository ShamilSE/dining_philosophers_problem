#include "philo.h"

pthread_mutex_t	mutex;

void*	lifecycle(void*	string)
{
	for (size_t i = 0; i < 20; i++) {
		printf("%s\n", string);
		usleep(10000);
	}
	return (NULL);
}

void	init_data(t_data* data)
{
	char**			pthread;
	size_t			index;
	t_philosopher**	philo;

	pthread = malloc(sizeof(char**));
	philo = malloc(sizeof(t_philosopher**));
	index = 0;
	while (index < data->philo_num)
	{
		philo[index] = malloc(sizeof(t_philosopher*));
		philo[index]->fork1 = index;
		if (data->philo_num == index + 1)
			philo[index]->fork2 = 0;
		else
			philo[index]->fork2 = index + 1;
		// printf("philo: %zu\nfork1 : %zu\nfork2: %zu\n------------------\n", index, philo[index]->fork1, philo[index]->fork2);
		// pthread_create(&thread1, NULL, lifecycle, (void*)string1);
		index++;
	}
	pthread_mutex_init(&mutex, NULL);
	// pthread_create(&thread2, NULL, hello_world, (void*)string2);

	// pthread_join(thread1, NULL);
	// pthread_join(thread2, NULL);

	// phtread_detach(); - when you dont give a duck about thread clean
	
	(void)data;
}

int	main(int ac, char** av)
{
	t_data*	data;
	// struct	timeval tv;

	if (ac != 6)
		ft_error("invalid argument count\n");
	data = parser(av);
	init_data(data);
	(void)data;
	// while (1) {
	// 	usleep(1000000);
	// 	gettimeofday(&tv, NULL);
	// 	printf("%ld\n", tv.tv_sec);
	// }
	free(data);
	return (0);
}
