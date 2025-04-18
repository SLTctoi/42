/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:52:26 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/10 12:54:19 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isdigit(int c)
{
	if (c >= 0 && c <= 9)
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("Custom: %d | Standard: %d\n", ft_isdigit('0'), isdigit('0'));
	printf("Custom: %d | Standard: %d\n", ft_isdigit('9'), isdigit('9'));
	printf("Custom: %d | Standard: %d\n", ft_isdigit('a'), isdigit('a'));
	printf("Custom: %d | Standard: %d\n", ft_isdigit(' '), isdigit(' '));
	printf("Custom: %d | Standard: %d\n", ft_isdigit(5), isdigit(5));
	return (0);
}
*/