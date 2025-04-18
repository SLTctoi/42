/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:25:44 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:26:20 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("Custom: %d | Standard: %d\n", ft_isprint('A'), isprint('A'));
	printf("Custom: %d | Standard: %d\n", ft_isprint(' '), isprint(' '));
	printf("Custom: %d | Standard: %d\n", ft_isprint(127), isprint(127));
	printf("Custom: %d | Standard: %d\n", ft_isprint('~'), isprint('~'));
	printf("Custom: %d | Standard: %d\n", ft_isprint(31), isprint(31));
	return (0);
}
*/
