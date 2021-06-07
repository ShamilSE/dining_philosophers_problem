#include "philo.h"

t_philosopher	*init_philo(size_t index)
{
	t_philosopher	*philo;

	philo = malloc(sizeof(t_philosopher));
	philo->ate_last_time = get_current_time(0);
	philo->id = index + 1;
	philo->ate_count = 0;
	return (philo);
}

void	sem_initialize(t_general *general)
{
	sem_unlink("forks");
	sem_unlink("talking");
	sem_unlink("time");
	sem_unlink("pair");
	general->time = sem_open("time", O_CREAT, 0777, 1);
	general->pair = sem_open("pair", O_CREAT, 0777, 1);
	general->forks = sem_open("forks", O_CREAT, 0777, general->philo_num);
	general->talking = sem_open("talking", O_CREAT, 0777, 1);
}

t_data	*init_data(char **av)
{
	t_data			*data;
	t_general		*general;
	size_t			index;
	t_philosopher	**philo;

	general = parser(av);
	data = malloc(sizeof(t_data));
	philo = malloc(sizeof(t_philosopher *) * general->philo_num);
	sem_initialize(general);
	index = 0;
	data->general = general;
	while (index < general->philo_num)
	{
		philo[index] = init_philo(index);
		philo[index]->general = general;
		index++;
	}
	data->philo = philo;
	return (data);
}
