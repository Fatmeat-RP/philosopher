#include <philosopher.h>

int	main(int ac, char **av)
{
	t_philos *philos;

	if (av <= 4)
		return (-1);
	philos->number_of_philosopher = ft_atoi(av[1]);
	philos->time_to_die = ft_atoi(av[2]);
	philos->time_to_eat = ft_atoi(av[3]);
	philos->time_to_sleep = ft_atoi(av[4]);
	if (av == 6)
		philos->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	get_error(philos);
	philosophe();
	return (0);
}