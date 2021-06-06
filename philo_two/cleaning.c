#include "../philo.h"

void	cleaning(t_data *data)
{
	size_t	index;

	index = 0;
	while (data->general->philo_num > index)
	{
		free(data->philo[index]);
		index++;
	}
	free(data->philo);
	// free(data->mutex);
	free(data->general);
}
