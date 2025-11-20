/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:56:00 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/12 11:28:34 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

void	ft_usleep(long time_in_ms)
{
	long	start_time;

	start_time = get_time();
	while (get_time() - start_time < time_in_ms)
		usleep(100);
}

void	print_action(t_philo *philo, char *action)
{
	long	timestamp;
	int		is_died;

	pthread_mutex_lock(&philo->rules->died_mutex);
	pthread_mutex_lock(&philo->rules->print_mutex);
	is_died = (action[0] == 'd' && action[1] == 'i' && action[2] == 'e');
	if (!philo->rules->someone_died || is_died)
	{
		timestamp = get_time() - philo->rules->start_time;
		printf("%ld %d %s\n", timestamp, philo->id + 1, action);
	}
	pthread_mutex_unlock(&philo->rules->print_mutex);
	pthread_mutex_unlock(&philo->rules->died_mutex);
}
