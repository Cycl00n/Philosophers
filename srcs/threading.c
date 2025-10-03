/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:00:18 by clnicola          #+#    #+#             */
/*   Updated: 2025/10/03 17:24:48 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	start_threads(t_table *table)
{
	int	i;

	table->starttime = gettimems();
	i = 0;
	while (i < table->nbr_philo)
	{
		if (pthread_create(&table->philos[i]->thread, NULL, &routine,
				table->philos[i]))
			return (0);
		i++;
	}
	if (table->nbr_philo > 1)
	{
		if (pthread_create(&table->monitor_thread, NULL, &monitor, table))
			return (0);
	}
	return (1);
}
