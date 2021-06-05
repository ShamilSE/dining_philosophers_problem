#include "philo.h"

void	eating(t_philosopher *philo)
{
	pthread_mutex_lock(philo->left_fork);
	log_philo("has taken left fork", philo);
	pthread_mutex_lock(philo->right_fork);
	log_philo("has taken right fork", philo);
	log_philo("is eating", philo);
	philo->ate_count++;
	if (philo->general->hungry && philo->ate_count == philo->general->hungry)
		philo->general->fulls++;
	philo->ate_last_time = get_current_time(0);
	usleep(philo->general->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
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
	pthread_t		die_check_thread;

	philo = (t_philosopher *)philosopher;
	if (pthread_create(&die_check_thread, NULL, die_check, (void *)philo) != 0)
		return ((void *)FAIL_CODE);
	pthread_detach(die_check_thread);
	while (!philo->general->stop_flag)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
