/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:16:07 by clnicola          #+#    #+#             */
/*   Updated: 2025/09/26 16:36:37 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_phil	t_phil;

typedef struct s_table
{
	size_t				nbr_philo;
	time_t				timetd;
	time_t				timete;
	time_t				timets;
	size_t				amount_eat_b4d;
	t_phil				**philos;
}						t_table;

typedef struct s_phil
{
	pthread_t			thread;
	int					id;
	t_table				*table;
}						t_phil;

#endif
