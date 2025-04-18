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
int	ft_alnum(int c)
{
	if ((c >= 0 && c <= 9)
		|| (c >= 'a' && c <= 'z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("Custom: %d | Standard: %d\n", ft_alnum('A'), isalnum('A'));
	printf("Custom: %d | Standard: %d\n", ft_alnum('z'), isalnum('z'));
	printf("Custom: %d | Standard: %d\n", ft_alnum('5'), isalnum('5'));
	printf("Custom: %d | Standard: %d\n", ft_alnum('@'), isalnum('@'));
	printf("Custom: %d | Standard: %d\n", ft_alnum(' '), isalnum(' '));
	printf("Custom: %d | Standard: %d\n", ft_alnum(0), isalnum(0));
	return (0);
}
*/