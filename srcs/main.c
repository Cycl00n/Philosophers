/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:15:58 by clnicola          #+#    #+#             */
/*   Updated: 2025/09/26 17:08:39 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_phil	**init_philo(t_table *table);
t_table	*init_table(int ac, char **av);

int	main(int ac, char **av)
{
	t_table	*table;

	table = NULL;
	if (ac < 5 || ac > 6)
	{
		printf("Wrong number of arguments.\n");
		exit(0);
	}
	table = init_table(ac, av);
	// pthread_create(&thread1, NULL, routine, (void *)&philos);
	// pthread_join(thread1, NULL);
}

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
	table->philos = init_philo(table);
	return (table);
}

t_phil	**init_philo(t_table *table)
{
	size_t	i;
	t_phil	**philos;

	i = 0;
	philos = malloc(sizeof(t_phil) * table->nbr_philo);
	while (i < table->nbr_philo)
	{
		philos[i] = malloc(sizeof(t_phil));
		philos[i]->id = i;
		philos[i]->table = table;
		i++;
	}
	return (philos);
}
