#include "philo.h"

void	eating(t_philosopher *philo)
{
	sem_wait(philo->general->pair);
	sem_wait(philo->general->forks);
	sem_wait(philo->general->forks);
	sem_post(philo->general->pair);
	log_philo("has taken forks", philo);
	log_philo("is eating", philo);
	philo->ate_count++;
	if (philo->general->hungry && philo->ate_count == philo->general->hungry)
	{
		sem_post(philo->general->full);
	}
	sem_wait(philo->general->time);
	philo->ate_last_time = get_current_time(0);
	sem_post(philo->general->time);
	usleep(philo->general->time_to_eat * 1000);
	log_philo("ate", philo);
	sem_post(philo->general->forks);
	sem_post(philo->general->forks);
	log_philo("has dropped forks", philo);
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

void	*lifecycle(t_philosopher *philo)
{
	pthread_t	monitor;

	pthread_create(&monitor, NULL, monitoring, (void *)philo);
	pthread_detach(monitor);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
