/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:22:36 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/12 11:27:59 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ligne 30 on crée un thread par philo
int	main(int ac, char **av)
{
	t_rules		rules;
	t_philo		*philos;
	pthread_t	monitor;
	int			i;

	if (init_all(&rules, &philos, ac, av))
		return (1);
	rules.start_time = get_time();
	i = -1;
	while (++i < rules.nb_philo)
		philos[i].last_meal = rules.start_time;
	i = -1;
	while (++i < rules.nb_philo)
		pthread_create(&philos[i].thread, NULL, philosopher_routine,
			&philos[i]);
	pthread_create(&monitor, NULL, monitor_routine, philos);
	i = -1;
	while (++i < rules.nb_philo)
		pthread_join(philos[i].thread, NULL);
	pthread_join(monitor, NULL);
	free_all(&rules, &philos);
	return (0);
}
