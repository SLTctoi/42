/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:22:40 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:23:41 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("Custom: %d | Standard: %d\n", ft_isalnum('A'), isalnum('A'));
	printf("Custom: %d | Standard: %d\n", ft_isalnum('z'), isalnum('z'));
	printf("Custom: %d | Standard: %d\n", ft_isalnum('5'), isalnum('5'));
	printf("Custom: %d | Standard: %d\n", ft_isalnum('@'), isalnum('@'));
	printf("Custom: %d | Standard: %d\n", ft_isalnum(' '), isalnum(' '));
	printf("Custom: %d | Standard: %d\n", ft_isalnum(0), isalnum(0));
	return (0);
}
*/