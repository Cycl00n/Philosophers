/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:15:58 by clnicola          #+#    #+#             */
/*   Updated: 2025/10/02 13:54:25 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table	*table;

	check_input(ac, av);
	table = init_table(ac, av);
	for (int i = 0; i < table->nbr_philo; i++)
		pthread_join(table->philos[i]->thread, NULL);
	return (0);
}
