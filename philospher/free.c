/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:55:31 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/12 11:10:36 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_rules *rules, t_philo **philos)
{
	int	i;

	if (rules->forks)
	{
		i = -1;
		while (++i < rules->nb_philo)
			pthread_mutex_destroy(&rules->forks[i]);
		free(rules->forks);
	}
	pthread_mutex_destroy(&rules->print_mutex);
	pthread_mutex_destroy(&rules->died_mutex);
	if (*philos)
	{
		i = -1;
		while (++i < rules->nb_philo)
			pthread_mutex_destroy(&(*philos)[i].meal_mutex);
		free(*philos);
		*philos = NULL;
	}
}
