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
	printf("%ld %zu is eating\n", get_current_time(philo->start_time), philo->id);
	pthread_mutex_unlock(&philo->general->talking);
	philo->ate_count++;
	// printf("philo ate count %zu\n ", philo->ate_count);
	if (philo->general->hungry && philo->ate_count == philo->general->hungry)
		philo->general->fulls++;
	philo->ate_last_time = get_current_time(0);
	usleep(philo->general->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philosopher* philo)
{
	pthread_mutex_lock(&philo->general->talking);
	printf("%ld %zu sleeping\n", get_current_time(philo->start_time), philo->id);
	pthread_mutex_unlock(&philo->general->talking);
	usleep(philo->general->time_to_sleep * 1000);
}

void	thinking(t_philosopher* philo)
{
	pthread_mutex_lock(&philo->general->talking);
	printf("%ld %zu thinking\n", get_current_time(philo->start_time), philo->id);
	pthread_mutex_unlock(&philo->general->talking);
}

void*	lifecycle(void*	philosopher)
{
	t_philosopher* philo = (t_philosopher*)philosopher;
	// pthread_create
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

		// while (data->general->philo_num > index)
		// {
		// 	if ((get_current_time(data->philo[index]->ate_last_time)) >= data->general->time_to_die)
		// 	{
		// 		pthread_mutex_lock(&data->general->talking);
		// 		printf(KRED "%ld %zu died\n" RESET, get_current_time(data->philo[index]->start_time), data->philo[index]->id);
		// 		pthread_mutex_unlock(&data->general->talking);
		// 		exit(0);
		// 	}
		// 	index++;
		// }
		// printf("fulls: %zu\n", data->general->fulls);