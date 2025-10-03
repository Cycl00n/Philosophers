/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:15:16 by clnicola          #+#    #+#             */
/*   Updated: 2025/10/03 17:34:31 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	starve(t_phil *philos)
{
	time_t	time;

	pthread_mutex_lock(&philos->timemeal_lock);
	time = gettimems();
	if ((time - philos->last_meal) >= philos->table->timetd)
	{
		print_status(philos, "died");
		philos->table->is_on = 0;
		pthread_mutex_unlock(&philos->timemeal_lock);
		return (1);
	}
	pthread_mutex_unlock(&philos->timemeal_lock);
	return (0);
}

int	kill_prog(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		if (starve(table->philos[i]))
			return (1);
		i++;
	}
	return (0);
}

void	*monitor(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	while (!kill_prog(table))
	{
		usleep(1000);
		continue ;
	}
	return (NULL);
}
