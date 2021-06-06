#include "philo.h"

void	*die_check(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	while (!philo->general->stop_flag)
	{
		if ((get_current_time(philo->ate_last_time))
			>= philo->general->time_to_die)
		{
			log_philo(KRED "died" RESET, philo);
			philo->general->stop_flag = 1;
			break ;
		}
	}
	return (NULL);
}
