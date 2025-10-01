/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:51:01 by clnicola          #+#    #+#             */
/*   Updated: 2025/10/01 17:08:50 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_table	*init_table(int ac, char **av)
{
	t_table	*table;

	ac = 0;
	table = malloc(sizeof(t_table) * 1);
	if (!table)
		return (0);
	table->nbr_philo = atoi(av[1]);
	table->timetd = atoi(av[2]);
	table->timete = atoi(av[3]);
	table->timets = atoi(av[4]);
	if (ac == 6)
		table->amount_eat_b4d = atoi(av[5]);
	table->forks_lock = init_fork(table);
	table->philos = init_philo(table);
	return (table);
}

t_phil	**init_philo(t_table *table)
{
	int		i;
	t_phil	**philos;

	i = 0;
	philos = malloc(sizeof(t_phil *) * table->nbr_philo);
	while (i < table->nbr_philo)
	{
		philos[i] = malloc(sizeof(t_phil));
		philos[i]->id = i;
		philos[i]->table = table;
		assign_fork(philos[i]);
		if (pthread_create(&philos[i]->thread, NULL, routine, philos[i]))
		{
			perror("Failed to create thread)");
			free(philos);
		}
		i++;
	}
	return (philos);
}

pthread_mutex_t	*init_fork(t_table *table)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * table->nbr_philo);
	if (!forks)
		exit(1);
	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_mutex_init(&forks[i], 0);
		i++;
	}
	return (forks);
}

void	assign_fork(t_phil *philos)
{
	if (philos->id % 2)
	{
		philos->fork[0] = (philos->id + 1) % philos->table->nbr_philo;
		philos->fork[1] = philos->id;
	}
	else
	{
		philos->fork[0] = philos->id;
		philos->fork[1] = (philos->id + 1) % philos->table->nbr_philo;
	}
}

void	*routine(void *data)
{
	t_phil	*philos;

	philos = data;
	printf("Routine %d\n", philos->id);
	return (data);
}
