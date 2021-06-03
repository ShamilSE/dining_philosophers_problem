#ifndef PHILO_H
#define PHILO_H

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\x1B[0m"

#include "../ftlib/ftlib.h"
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct	s_general {
	size_t		philo_num;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		hungry;
}				t_general;

typedef struct		s_philosopher {
	size_t			ate;
	pthread_mutex_t*			left_fork;
	pthread_mutex_t*			right_fork;
	pthread_t		thread;
	size_t			status;
	int				start_time;
	size_t			id;
	t_general*		general;
}					t_philosopher;

typedef struct			s_data {
	t_general*			general;
	t_philosopher**		philo;
	pthread_mutex_t*	mutex;
}						t_data;

//parse
int			is_args_digit(char** av);
void		ft_error(char* msg);
t_general*	parser(char** av);
t_data*		init_data(char** av);
//logic
void*		lifecycle(void*	philosopher);
//other
int			get_current_time(void);

#endif
