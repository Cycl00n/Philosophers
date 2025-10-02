/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:14:50 by clnicola          #+#    #+#             */
/*   Updated: 2025/10/02 17:46:31 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat_routine(t_phil *philos)
{
	while (1)
	{
		pthread_mutex_lock(&philos->table->forks_lock[philos->fork[0]]);
		print_status(philos, "started eating");
		pthread_mutex_lock(&philos->table->forks_lock[philos->fork[1]]);
		usleep(philos->table->timete * 1000);
		pthread_mutex_unlock(&philos->table->forks_lock[philos->fork[1]]);
		pthread_mutex_unlock(&philos->table->forks_lock[philos->fork[0]]);
		usleep(10);
	}
}

/*void	sleep_routine(t_phil *philos)
{
}*/