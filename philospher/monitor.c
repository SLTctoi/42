/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:55:49 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/14 20:28:21 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// la mort est check ici 
// (thread qui tourne en boucle et qui check les cond pour mourir)
int	check_death(t_philo *philo)
{
	long	time_since;
	long	current;
	int		should_die;
	int		meals_done;

	pthread_mutex_lock(&philo->meal_mutex);
	current = get_time();
	time_since = current - philo->last_meal;
	meals_done = philo->meals_eaten;
	pthread_mutex_unlock(&philo->meal_mutex);
	if (philo->rules->meals_required != -1 
		&& meals_done >= philo->rules->meals_required)
		return (0);
	should_die = time_since > philo->rules->time_to_die;
	if (should_die)
	{
		pthread_mutex_lock(&philo->rules->died_mutex);
		if (!philo->rules->someone_died)
		{
			philo->rules->someone_died = 1;
			pthread_mutex_unlock(&philo->rules->died_mutex);
			print_action(philo, "died");
			return (1);
		}
		pthread_mutex_unlock(&philo->rules->died_mutex);
	}
	return (0);
}

int	check_meals(t_philo *philos)
{
	int	i;
	int	full_count;

	if (philos->rules->meals_required == -1)
		return (0);
	full_count = 0;
	i = -1;
	while (++i < philos->rules->nb_philo)
	{
		pthread_mutex_lock(&philos[i].meal_mutex);
		if (philos[i].meals_eaten >= philos->rules->meals_required)
			full_count++;
		pthread_mutex_unlock(&philos[i].meal_mutex);
	}
	if (full_count == philos->rules->nb_philo)
		return (1);
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)arg;
	while (1)
	{
		if (check_meals(philos))
			return (NULL);
		i = -1;
		while (++i < philos->rules->nb_philo)
		{
			if (check_death(&philos[i]))
				return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
