/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:45:37 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/14 18:19:15 by mchrispe         ###   ########.fr       */
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
	print_action(philo, "is thinking");
}
