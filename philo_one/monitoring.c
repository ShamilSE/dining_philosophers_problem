#include "philo.h"

void	*ate_monitoring(void *_data)
{
	size_t	index;
	t_data	*data;

	data = (t_data *)_data;
	while (1)
	{
		index = 0;
		if (data->general->fulls == data->general->philo_num)
		{
			printf(KGRN "everybody ate %zu times\n"
				RESET, data->general->hungry);
			exit(0);
		}
	}
}
