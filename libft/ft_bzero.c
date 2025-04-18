/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:29:38 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:30:38 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*dest;

	dest = s;
	i = 0;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	custom[10] = "abcdef";
	char	standard[10] = "abcdef";
	char	custom2[10] = "123456";
	char	standard2[10] = "123456";
	char	custom3[10] = "hello";
	char	standard3[10] = "hello";

	ft_bzero(custom, 3);
	bzero(standard, 3);
	printf("Custom: %s | Standard: %s\n", custom, standard);
	ft_bzero(custom2, 6);
	bzero(standard2, 6);
	printf("Custom: %s | Standard: %s\n", custom2, standard2);
	ft_bzero(custom3, 0);
	bzero(standard3, 0);
	printf("Custom: %s | Standard: %s\n", custom3, standard3);
	return (0);
}
*/
