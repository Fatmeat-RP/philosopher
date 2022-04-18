#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <pthread.h>

typedef struct s_philosophers t_philos;
typedef struct s_philosopher t_philo;
typedef unsigned long t_uint64;
typedef pthread_mutex_t t_id;

struct s_philosophers
{
	t_philo	*first;
	t_philo	*last;
	size_t	size;
	long	timestamp;
	int		number_of_philosopher;
	int		time_to_die;/*in millisecond*/
	int		time_to_eat;/*in millisecond*/
	int		time_to_sleep;/*in millisecond*/
	int		number_of_times_each_philosopher_must_eat;
};

struct s_philosopher
{
	int				id;
	int				fork;
	t_id			*mutex;/* mutex id */
	t_philo	*prev;
	t_philo	*next;
}

#endif