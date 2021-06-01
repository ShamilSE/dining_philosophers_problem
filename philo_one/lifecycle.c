#include "philo.h"

void	eating(t_philosopher* philo)
{
	printf("%zu: eating\n", philo->fork1);
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

void*	lifecycle(void*	philo)
{
	philo = (t_philosopher*)philo;
	eating(philo);
	// pthread_mutex_lock(&mutex);
	// pthread_mutex_unlock(&mutex);
	// sleeping(philosopher);
	// thinking(philosopher);
	return (NULL);
}
