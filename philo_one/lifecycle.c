#include "philo.h"

void	eating(t_data* data)
{
	// pthread_mutex_lock(&mutex);
	// pthread_mutex_unlock(&mutex);
	// size_t	i, ii;

	// i = 0;
	// while (data->philo_num > i)
	// {
	// 	ii = 0;
	// 	while (data->philo_num > ii)
	// 	{
	// 		if (data->philo[i]->fork1 == data->forks[ii] || 
	// 			data->philo[i]->fork2 == data->forks[ii])

	// 		ii++;
	// 	}
	// 	i++;
	// }
	printf("%zu: eating\n", data->philo[data->index]->left_fork);
	// usleep(2000000);
}

void	sleeping()
{
	printf("sleeping\n");
}

void	thinking()
{
	printf("thinking\n");
}

void*	lifecycle(void*	data)
{
	eating(data);
	// sleeping(philosopher);
	// thinking(philosopher);
	return (NULL);
}
