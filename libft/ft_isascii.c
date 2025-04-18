/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:24:29 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:25:19 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("Custom: %d | Standard: %d\n", ft_isascii('A'), isascii('A'));
	printf("Custom: %d | Standard: %d\n", ft_isascii(128), isascii(128));
	printf("Custom: %d | Standard: %d\n", ft_isascii(0), isascii(0));
	printf("Custom: %d | Standard: %d\n", ft_isascii(127), isascii(127));
	printf("Custom: %d | Standard: %d\n", ft_isascii(-1), isascii(-1));
	return (0);
}
*/
