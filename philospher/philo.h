/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:08:58 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/17 11:08:58 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_rules
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_required;
	int				someone_died;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	died_mutex;
	long			start_time;
}	t_rules;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_rules			*rules;
	pthread_t		thread;
}	t_philo;

// main.c
int		main(int ac, char **av);

// init.c
int		init_all(t_rules *rules, t_philo **philos, int ac, char **av);

// routine.c
void	*philosopher_routine(void *arg);
void	eating_routine(t_philo *philo);
void	sleeping_routine(t_philo *philo);
void	thinking_routine(t_philo *philo);

// monitor.c
void	*monitor_routine(void *arg);
int		check_death(t_philo *philo);
int		check_meals(t_philo *philo);

// utils.c
long	get_time(void);
int		ft_atoi(const char *str);
void	ft_usleep(long time_in_ms);
void	print_action(t_philo *philo, char *action);

// free.c
void	free_all(t_rules *rules, t_philo **philos);

#endif
