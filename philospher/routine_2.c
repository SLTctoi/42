/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:45:37 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/04 13:09:10 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping_routine(t_philo *philo)
{
	print_action(philo, "is sleeping");
	ft_usleep(philo->rules->time_to_sleep);
}

void	thinking_routine(t_philo *philo)
{
	long	think_time;

	print_action(philo, "is thinking");
	if (philo->rules->nb_philo % 2 != 0)
	{
		think_time = (philo->rules->time_to_eat * 2) - philo->rules->time_to_sleep;
		if (think_time < 0)
			think_time = 0;
		if (think_time > 0)
			ft_usleep(think_time);
	}
}
