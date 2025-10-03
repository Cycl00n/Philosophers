/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:16:07 by clnicola          #+#    #+#             */
/*   Updated: 2025/10/03 17:10:57 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_phil	t_phil;

typedef struct s_table
{
	int					nbr_philo;
	int					is_on;
	time_t				starttime;
	time_t				timetd;
	time_t				timete;
	time_t				timets;
	size_t				amount_eat_b4d;
	t_phil				**philos;
	pthread_t			monitor_thread;
	pthread_mutex_t		*forks_lock;
	pthread_mutex_t		prog_lock;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		prog_stop_lock;
}						t_table;

typedef struct s_phil
{
	pthread_mutex_t		timemeal_lock;
	pthread_t			thread;
	int					id;
	int					fork[2];
	int					amout_eaten;
	t_table				*table;
	time_t				last_meal;
}						t_phil;

t_phil					**init_philo(t_table *table);
t_table					*init_table(int ac, char **av);
void					*routine(void *data);
void					assign_fork(t_phil *philos);
pthread_mutex_t			*init_fork(t_table *table);
int						check_input(int ac, char **argv);
void					eat_sleep_routine(t_phil *philos);
time_t					gettimems(void);
void					print_status(t_phil *philos, char *str);
void					thinking_routine(t_phil *philos);
void					*monitor(void *data);
int						start_threads(t_table *table);

#endif
