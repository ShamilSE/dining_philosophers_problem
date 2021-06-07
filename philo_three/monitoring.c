#include "philo.h"

static int	is_dead(t_philosopher *philo)
{
	size_t	index;

	index = 0;
	while (index < philo->general->philo_num)
	{
		sem_wait(philo->general->time);
		if ((get_current_time(philo->ate_last_time))
			> philo->general->time_to_die)
		{
			sem_wait(philo->general->talking);
			printf(KRED "%zu %zu died\n" RESET,
				get_current_time(philo->start_time),
				philo->id);
			sem_post(philo->general->death);
			return (1);
		}
		sem_post(philo->general->time);
		index++;
	}
	return (0);
}

void	*monitoring(void *philo)
{
	while (1)
	{
		if (is_dead(philo))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
