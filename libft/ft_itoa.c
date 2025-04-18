/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:43:17 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:43:40 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*s1;
	long	nb;

	nb = n;
	len = ft_intlen(n);
	s1 = malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	s1[len] = '\0';
	if (nb < 0)
	{
		s1[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		s1[0] = '0';
	while (nb > 0)
	{
		len--;
		s1[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s1);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("Custom: %s | Standard: %s\n", ft_itoa(42), "42");
	printf("Custom: %s | Standard: %s\n", ft_itoa(-42), "-42");
	printf("Custom: %s | Standard: %s\n", ft_itoa(0), "0");
	printf("Custom: %s | Standard: %s\n", ft_itoa(123456), "123456");
	printf("Custom: %s | Standard: %s\n", ft_itoa(-123456), "-123456");
	return (0);
}
*/