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

#include "ftlib/ftlib.h"
#include <stdio.h>
#include <pthread.h>

typedef struct	s_data {
	size_t		philo_num;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		hungry;
}				t_data;

int		is_args_digit(char** av);
void	ft_error(char* msg);
t_data*	parser(char** av);

#endif