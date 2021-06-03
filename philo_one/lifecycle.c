#include "philo.h"

void	eating(t_philosopher* philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->general->talking);
	printf("%ld %zu has taken left fork\n", get_current_time(philo->start_time), philo->id);
	pthread_mutex_unlock(&philo->general->talking);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->general->talking);
	printf("%ld %zu has taken right fork\n", get_current_time(philo->start_time), philo->id);;
	pthread_mutex_unlock(&philo->general->talking);
	printf("%ld %zu is eating\n", get_current_time(philo->start_time), philo->id);
	philo->status++;
	philo->ate++;
	usleep(philo->general->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

// void	sleeping(t_data* data)
// {
// 	if (data->philo[data->index]->status != 1)
// 		return ;
// 	usleep(data->general->time_to_sleep * 1000);
// 	data->philo[data->index]->status--; // increment status later
// 	printf("%i %zu sleeping\n", get_current_time() - data->philo[data->index]->start_time, data->index);
// }

void	thinking()
{
	printf("thinking\n");
}

int		all_ate_check(t_data* data)
{
	size_t	index;

	index = 0;
	if (!data->general->hungry)
		return (0);
	while (index < data->general->philo_num)
	{
		if (data->philo[index]->ate < data->general->hungry)
			return (0);
		index++;
	}
	return (1);
}

void*	lifecycle(void*	philosopher)
{
	t_philosopher* philo = (t_philosopher*)philosopher;
	while (1)
	{
		eating(philo);
		// if (data->philo[data->index]->status == 1)
		// sleeping(philo);
		// if (data->philo[data->index]->status == 2)
			// thinking(philosopher);
		
		// if (all_ate_check(philo))
		// 	return (NULL);
	}
	return (NULL);
}

// 0 - need to eat stat
// 1 - need to sleep stat
// 2 - need to think stat