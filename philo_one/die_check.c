#include "philo.h"

void	*die_check(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	while (1)
	{
		if ((get_current_time(philo->ate_last_time))
			>= philo->general->time_to_die)
		{
			pthread_mutex_lock(&philo->general->talking);
			printf(KRED "%ld %zu died\n"
				RESET, get_current_time(philo->start_time), philo->id);
			pthread_mutex_unlock(&philo->general->talking);
			exit(0);
		}
	}
}
