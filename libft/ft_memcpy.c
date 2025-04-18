/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:31:53 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:32:23 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ud;
	const unsigned char	*us;

	ud = (unsigned char *)dest;
	us = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ud[i] = us[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src1[] = "Hello, World!";
	char	dest1[20];
	char	dest2[20];
	char	src2[] = "";
	char	dest3[10];
	char	dest4[10];
	char	src3[] = "42";
	char	dest5[10];
	char	dest6[10];

	printf("Custom: %s | Standard: %s\n", (char *)ft_memcpy(dest1, src1, 13),
		(char *)memcpy(dest2, src1, 13));
	printf("Custom: %s | Standard: %s\n", (char *)ft_memcpy(dest3, src2, 1),
		(char *)memcpy(dest4, src2, 1));
	printf("Custom: %s | Standard: %s\n", (char *)ft_memcpy(dest5, src3, 3),
		(char *)memcpy(dest6, src3, 3));
	return (0);
}
*/