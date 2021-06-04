#include "philo.h"

void	eating_odd(t_philosopher* philo)
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
	// philo->ate_count++;
	// if (philo->general->hungry && philo->ate_count >= philo->general->hungry)
	// 	philo->is_full = 1;
	usleep(philo->general->time_to_eat * 1000);
	philo->ate_last_time = get_current_time(0);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eating_even(t_philosopher* philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->general->talking);
	printf("%ld %zu has taken right fork\n", get_current_time(philo->start_time), philo->id);
	pthread_mutex_unlock(&philo->general->talking);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->general->talking);
	printf("%ld %zu has taken left fork\n", get_current_time(philo->start_time), philo->id);;
	printf("%ld %zu is eating\n", get_current_time(philo->start_time), philo->id);
	pthread_mutex_unlock(&philo->general->talking);
	// philo->ate_count++;
	// if (philo->general->hungry && philo->ate_count >= philo->general->hungry)
	// 	philo->is_full = 1;
	usleep(philo->general->time_to_eat * 1000);
	philo->ate_last_time = get_current_time(0);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
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
	while (1)
	{
		if ((philo->id % 2) == 0)
			eating_odd(philo);
		else
			eating_even(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
