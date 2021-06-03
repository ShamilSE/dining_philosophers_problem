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
	pthread_mutex_unlock(&philo->general->talking);
	printf("%ld %zu is eating\n", get_current_time(philo->start_time), philo->id);
	// philo->status++;
	philo->ate_count++;
	philo->ate_last_time = get_current_time(0);
	usleep(philo->general->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eating(t_philosopher* philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->general->talking);
	printf("%ld %zu has taken right fork\n", get_current_time(philo->start_time), philo->id);
	pthread_mutex_unlock(&philo->general->talking);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->general->talking);
	printf("%ld %zu has taken left fork\n", get_current_time(philo->start_time), philo->id);;
	pthread_mutex_unlock(&philo->general->talking);
	printf("%ld %zu is eating\n", get_current_time(philo->start_time), philo->id);
	// philo->status++;
	philo->ate_count++;
	philo->ate_last_time = get_current_time(0);
	usleep(philo->general->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleeping(t_philosopher* philo)
{
	// if (data->philo[data->index]->status != 1)
	// 	return ;
	usleep(philo->general->time_to_sleep * 1000);
	// philo->status--; // increment status l_countr
	pthread_mutex_lock(&philo->general->talking);
	printf("%ld %zu sleeping\n", get_current_time(philo->start_time), philo->id);
	pthread_mutex_unlock(&philo->general->talking);
}

void	thinking(t_philosopher* philo)
{
	pthread_mutex_lock(&philo->general->talking);
	printf("%ld %zu thinking\n", get_current_time(philo->start_time), philo->id);
	pthread_mutex_unlock(&philo->general->talking);
}

// int		all_ate_check(t_philosopher* philo)
// {
// 	size_t	index;

// 	index = 0;
// 	if (!data->general->hungry)
// 		return (0);
// 	while (index < data->general->philo_num)
// 	{
// 		if (data->philo[index]->ate < data->general->hungry)
// 			return (0);
// 		index++;
// 	}
// 	return (1);
// }

void*	lifecycle(void*	philosopher)
{
	t_philosopher* philo = (t_philosopher*)philosopher;
	while (1)
	{
		if ((philo->id % 2) == 0)
			eating_odd(philo);
		else
			eating(philo);
		// if (data->philo[data->index]->status == 1)
		sleeping(philo);
		// if (data->philo[data->index]->status == 2)
		thinking(philosopher);
		
		// if (all_ate_check(philo))
		// 	return (NULL);
	}
	return (NULL);
}

// 0 - need to eat stat
// 1 - need to sleep stat
// 2 - need to think stat