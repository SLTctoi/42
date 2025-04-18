/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:39:24 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/18 13:08:41 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	sign;

	sign = 1;
	nb = 0;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * nb);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("Custom: %d | Standard: %d\n", ft_atoi("42"), atoi("42"));
	printf("Custom: %d | Standard: %d\n", ft_atoi("-42"), atoi("-42"));
	printf("Custom: %d | Standard: %d\n", ft_atoi("   +123"), atoi("   +123"));
	printf("Custom: %d | Standard: %d\n", ft_atoi("   -00123"), atoi("
			-00123"));
	printf("Custom: %d | Standard: %d\n", ft_atoi("0"), atoi("0"));
	printf("Custom: %d | Standard: %d\n", ft_atoi("   2147483647"),
		atoi("   2147483647"));
	printf("Custom: %d | Standard: %d\n", ft_atoi("   -2147483648"), atoi("
			-2147483648"));
	printf("Custom: %d | Standard: %d\n", ft_atoi("   42abc"),
		atoi("   42abc"));
	printf("Custom: %d | Standard: %d\n", ft_atoi("abc42"), atoi("abc42"));
	printf("Custom: %d | Standard: %d\n", ft_atoi(""), atoi(""));
	return (0);
}
*/
