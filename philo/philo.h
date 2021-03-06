#ifndef PHILO_H
# define PHILO_H

# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define RESET "\x1B[0m"

# define SUCCESS_CODE 0
# define FAIL_CODE 1

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_general {
	size_t			philo_num;
	long			time_to_die;
	size_t			time_to_eat;
	long			time_to_sleep;
	size_t			hungry;
	pthread_mutex_t	talking;
	size_t			fulls;
	pthread_mutex_t	time;
	size_t			everybody_alive;
}					t_general;

typedef struct s_philosopher {
	size_t			ate_count;
	long			ate_last_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	long			start_time;
	size_t			id;
	t_general		*general;
}					t_philosopher;

typedef struct s_data {
	t_general			*general;
	t_philosopher		**philo;
	pthread_mutex_t		*mutex;
}						t_data;

int			is_args_digit(char **av);
void		ft_error(char *msg);
t_general	*parser(char **av);
t_data		*init_data(char **av);
void		*lifecycle(void *philosopher);
void		*monitoring(void *data);
long		get_current_time(long start_time);
void		*die_check(void *philosopher);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		log_philo(char *message, t_philosopher *philo);
void		cleaning(t_data *data);

#endif
