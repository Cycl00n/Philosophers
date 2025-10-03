/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:23:23 by clnicola          #+#    #+#             */
/*   Updated: 2025/10/03 15:41:37 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_input(int ac, char **argv)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		printf("Wrong number of arguments.\n");
		exit(1);
	}
	while (i < ac)
	{
		if (!is_num(argv[i]))
		{
			printf("Arguments must be positive numbers only.\n");
			exit(1);
		}
		i++;
	}
	return (1);
}

time_t	gettimems(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_status(t_phil *philos, char *str)
{
	pthread_mutex_lock(&philos->table->write_lock);
	if (philos->table->is_on)
		printf("%ld ms: Philosopher %d %s\n", gettimems()
			- philos->table->starttime, philos->id + 1, str);
	pthread_mutex_unlock(&philos->table->write_lock);
}
