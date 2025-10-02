/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:14:50 by clnicola          #+#    #+#             */
/*   Updated: 2025/10/02 15:26:39 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat_routine(t_phil *philos)
{
	while (1)
	{
		pthread_mutex_lock(&philos->table->forks_lock[philos->fork[0]]);
		printf("Philo %d's got fork %d\n", philos->id, philos->fork[0]);
		pthread_mutex_lock(&philos->table->forks_lock[philos->fork[1]]);
		printf("Philo %d's got fork %d\n", philos->id, philos->fork[1]);
		printf("Philo %d's is eating with fork %d & %d\n", philos->id,
			philos->fork[0], philos->fork[1]);
		usleep(2000);
		pthread_mutex_unlock(&philos->table->forks_lock[philos->fork[1]]);
		pthread_mutex_unlock(&philos->table->forks_lock[philos->fork[0]]);
		printf("Philo %d released forks\n", philos->id);
	}
}