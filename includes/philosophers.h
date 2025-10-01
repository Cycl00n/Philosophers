/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:16:07 by clnicola          #+#    #+#             */
/*   Updated: 2025/10/01 16:32:48 by clnicola         ###   ########.fr       */
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
	int					nbr_philo;
	time_t				timetd;
	time_t				timete;
	time_t				timets;
	size_t				amount_eat_b4d;
	t_phil				**philos;
	pthread_mutex_t		*forks_lock;
}						t_table;

typedef struct s_phil
{
	pthread_t			thread;
	int					id;
	int					fork[2];
	t_table				*table;
}						t_phil;

t_phil					**init_philo(t_table *table);
t_table					*init_table(int ac, char **av);
void					*routine(void *data);
void					assign_fork(t_phil *philos);
pthread_mutex_t			*init_fork(t_table *table);
int						check_input(int ac, char **argv);

#endif
