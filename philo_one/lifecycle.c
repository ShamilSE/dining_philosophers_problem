#include "philo.h"

void	eating(t_data* data)
{
	int		is_left_fork_taken;
	int		is_right_fork_taken;

	is_left_fork_taken = 0;
	is_left_fork_taken = 0;
	if (pthread_mutex_lock(&data->mutex[data->philo[data->index]->left_fork]) == 0)
	{
		is_left_fork_taken = 1;
		printf("%d %zu has taken a left fork\n", get_current_time() - data->start_time, data->index);
	}
	if (pthread_mutex_lock(&data->mutex[data->philo[data->index]->right_fork]) == 0)
	{
		is_right_fork_taken = 1;
		printf("%d %zu has taken a right fork\n", get_current_time() - data->start_time, data->index);
	}
	if (is_left_fork_taken && is_right_fork_taken)
		printf("%d %zu is eating\n", get_current_time() - data->start_time, data->index);
	usleep(data->general->time_to_eat * 1000);
	pthread_mutex_unlock(&data->mutex[data->philo[data->index]->left_fork]);
	pthread_mutex_unlock(&data->mutex[data->philo[data->index]->right_fork]);
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
