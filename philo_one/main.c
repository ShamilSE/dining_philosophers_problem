#include "philo.h"

// pthread_mutex_t	mutex;

void*	hello_world(void*	string)
{
	for (size_t i = 0; i < 20; i++) {
		
		printf("%s\n", string);
		usleep(10000);
	}
	return (NULL);
}

void	philosophy(t_data* data)
{
	// pthread_t	thread1, thread2;
	// char*		string1 = "\x1B[31m_1_1_1_1_1_1_1_1_1_1_1_1\x1B[0m";
	// char*		string2 = "\x1B[32m2_2_2_2_2_2_2_2_2_2_2_2_\x1B[0m";

	// // pthread_mutex_init(&mutex, NULL);
	// pthread_create(&thread1, NULL, hello_world, (void*)string1);
	// pthread_create(&thread2, NULL, hello_world, (void*)string2);

	// pthread_join(thread1, NULL);
	// pthread_join(thread2, NULL);


	
	(void)data;
}

int	main(int ac, char** av)
{
	t_data*	data;
	if (ac != 6)
		ft_error("invalid argument count\n");
	data = parser(av);
	philosophy(data);
	free(data);
	return (0);
}
