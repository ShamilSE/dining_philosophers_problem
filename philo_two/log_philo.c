#include "philo.h"

void	log_philo(char *message, t_philosopher *philo)
{
	sem_wait(philo->general->talking);
	printf("%zu %zu %s\n", get_current_time(philo->start_time), philo->id, message);
	sem_post(philo->general->talking);
}
