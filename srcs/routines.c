/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:14:50 by clnicola          #+#    #+#             */
/*   Updated: 2025/10/03 17:27:26 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat_sleep_routine(t_phil *philos)
{
	pthread_mutex_lock(&philos->table->forks_lock[philos->fork[0]]);
	print_status(philos, "has taken a fork");
	pthread_mutex_lock(&philos->table->forks_lock[philos->fork[1]]);
	print_status(philos, "has taken a fork");
	print_status(philos, "is eating");
	pthread_mutex_lock(&philos->timemeal_lock);
	philos->last_meal = gettimems();
	philos->amout_eaten += 1;
	pthread_mutex_unlock(&philos->timemeal_lock);
	usleep(philos->table->timete * 1000);
	print_status(philos, "is sleeping");
	pthread_mutex_unlock(&philos->table->forks_lock[philos->fork[1]]);
	pthread_mutex_unlock(&philos->table->forks_lock[philos->fork[0]]);
	usleep(philos->table->timets * 1000);
}

void	thinking_routine(t_phil *philos)
{
	time_t	timett;

	pthread_mutex_lock(&philos->timemeal_lock);
	timett = (philos->table->timetd - (gettimems() - philos->last_meal)
			- philos->table->timete) / 2;
	pthread_mutex_unlock(&philos->timemeal_lock);
	if (timett <= 0)
		timett = 1;
	else if (timett > 500)
		timett = 200;
	print_status(philos, "is thinking");
	usleep(timett * 1000);
}

void	*routine(void *data)
{
	t_phil	*philos;

	philos = data;
	pthread_mutex_lock(&philos->timemeal_lock);
	philos->last_meal = philos->table->starttime;
	pthread_mutex_unlock(&philos->timemeal_lock);
	if (philos->id % 2 == 0)
		thinking_routine(philos);
	while (philos->table->is_on == 1)
	{
		eat_sleep_routine(philos);
		thinking_routine(philos);
	}
	return (data);
}
