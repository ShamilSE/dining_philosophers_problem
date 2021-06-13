#include "philo.h"

void	log_philo(char *message, t_philosopher *philo)
{
	pthread_mutex_lock(&philo->general->talking);
	if (philo->general->everybody_alive)
	{
		printf("%zu %zu %s\n",
			get_current_time(philo->start_time), philo->id, message);
	}
	pthread_mutex_unlock(&philo->general->talking);
}
