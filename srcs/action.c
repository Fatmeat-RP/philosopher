#include <philosopher.h>

int	dying(t_philo *philo, t_philos *philos)
{
	pthread_mutex_destroy(philo->id);
	printf("%ld : %i : died\n", philos->timestamp, philo->id);
	return (0);
}

int sleeping(t_philo *philo, t_philos *philos)
{
	pthread_mutex_lock(philo->id);
	usleep(philos->time_to_sleep);
	printf("%ld : %i : is sleeping\n", philos->timestamp, philo->id);
	pthread_mutex_unlock(philo->id);
	return (0);
}

int eating(t_philo *philo, t_philos *philos)
{
	pthread_mutex_lock(philo->id);
	usleep(philos->time_to_eat);
	printf("%ld : %i : is eating\n", philos->timestamp, philo->id);
	pthread_mutex_unlock(philo->id);
	return (0);
}

int thinking(t_philo *philo, t_philos *philos)
{
	printf("%ld : %i : is thinking\n", philos->timestamp, philo->id);
	return (0);
}

int take_a_fork(t_philo *philo, t_philos *philos)
{
	if (forkstat())
	{
		philo->prev->fork = 0;
		philo->fork = 1;
		printf("%ld : %i : has taken a fork\n", philos->timestamp, philo->id);
	}
	else
		return (-1);
	return (0);
}