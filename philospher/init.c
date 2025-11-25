/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:55:35 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/12 11:11:35 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ligne 14 j'alloue bien le nombre de forks en fonction du nombre de philo
static int	init_rules(t_rules *rules, t_philo **philos, int ac, char **av)
{
	int	i;

	rules->nb_philo = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		rules->meals_required = ft_atoi(av[5]);
	else
		rules->meals_required = -1;
	rules->someone_died = 0;
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nb_philo);
	if (!rules->forks)
		return (0);
	*philos = malloc(sizeof(t_philo) * rules->nb_philo);
	if (!*philos)
		return (0);
	i = -1;
	while (++i < rules->nb_philo)
		pthread_mutex_init(&rules->forks[i], NULL);
	pthread_mutex_init(&rules->print_mutex, NULL);
	pthread_mutex_init(&rules->died_mutex, NULL);
	return (1);
}

static void	init_philos(t_rules *rules, t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philo)
	{
		(*philos)[i].id = i;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].last_meal = 0;
		(*philos)[i].left_fork = &rules->forks[i];
		(*philos)[i].right_fork = &rules->forks[(i + 1) % rules->nb_philo];
		(*philos)[i].rules = rules;
		pthread_mutex_init(&(*philos)[i].meal_mutex, NULL);
	}
}

static int	validate_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '+')
			j++;
		if (!av[i][j])
			return (0);
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		if (ft_atoi(av[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}

int	init_all(t_rules *rules, t_philo **philos, int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (write(2, "Error: Bad arguments\n", 21) && 1);
	if (!validate_args(ac, av))
		return (write(2, "Error: Invalid arguments\n", 25) && 1);
	if (!init_rules(rules, philos, ac, av))
		return (write(2, "Error: Initialization failed\n", 29) && 1);
	init_philos(rules, philos);
	return (0);
}
