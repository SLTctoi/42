/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:55:57 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/12 11:55:50 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
	}
	pthread_mutex_lock(&philo->rules->died_mutex);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->rules->died_mutex);
	print_action(philo, "is eating");
	ft_usleep(philo->rules->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping_routine(t_philo *philo)
{
	print_action(philo, "is sleeping");
	ft_usleep(philo->rules->time_to_sleep);
}

void	thinking_routine(t_philo *philo)
{
	print_action(philo, "is thinking");
}

static int	philosopher_util(t_philo *philo)
{
	if (philo->rules->nb_philo == 1)
	{
		print_action(philo, "has taken a fork");
		ft_usleep(philo->rules->time_to_die);
		return (1);
	}
	if (philo->id % 2 == 0)
		usleep(philo->rules->time_to_eat / 2);
	return (0);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philosopher_util(philo))
		return (NULL);
	while (1)
	{
		pthread_mutex_lock(&philo->rules->died_mutex);
		if (philo->rules->someone_died)
		{
			pthread_mutex_unlock(&philo->rules->died_mutex);
			break ;
		}
		if (philo->rules->meals_required != -1
			&& philo->meals_eaten >= philo->rules->meals_required)
		{
			pthread_mutex_unlock(&philo->rules->died_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->rules->died_mutex);
		eating_routine(philo);
		sleeping_routine(philo);
		thinking_routine(philo);
	}
	return (NULL);
}
