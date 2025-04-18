/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:28:23 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:29:25 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	custom[50];
	char	standard[50];

	ft_memset(custom, 'A', 10);
	memset(standard, 'A', 10);
	printf("Custom: %.*s | Standard: %.*s\n", 10, custom, 10, standard);
	ft_memset(custom, 'B', 5);
	memset(standard, 'B', 5);
	printf("Custom: %.*s | Standard: %.*s\n", 10, custom, 10, standard);
	ft_memset(custom, 0, 10);
	memset(standard, 0, 10);
	printf("Custom: %.*s | Standard: %.*s\n", 10, custom, 10, standard);
	return (0);
}
*/