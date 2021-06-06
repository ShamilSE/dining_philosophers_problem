#include "philo.h"

void	eating(t_philosopher *philo)
{
	if (philo->id & 1)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	log_philo("has taken forks", philo);
	log_philo("is eating", philo);
	philo->ate_count++;
	if (philo->general->hungry && philo->ate_count == philo->general->hungry)
		philo->general->fulls++;
	pthread_mutex_lock(&philo->general->time);
	philo->ate_last_time = get_current_time(0);
	pthread_mutex_unlock(&philo->general->time);
	usleep(philo->general->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleeping(t_philosopher *philo)
{
	log_philo("sleeping", philo);
	usleep(philo->general->time_to_sleep * 1000);
}

void	thinking(t_philosopher *philo)
{
	log_philo("thinking", philo);
}

void	*lifecycle(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	pthread_detach(philo->thread);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
