/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:10:43 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 13:11:03 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;
	size_t			i;

	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (i < n)
	{
		if (us1[i] != us2[i])
			return ((unsigned char)us1[i] - (unsigned char)us2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("Custom: %d | Standard: %d\n", ft_memcmp("abc", "abc", 3),
		memcmp("abc", "abc", 3));
	printf("Custom: %d | Standard: %d\n", ft_memcmp("abc", "abd", 3),
		memcmp("abc", "abd", 3));
	printf("Custom: %d | Standard: %d\n", ft_memcmp("abc", "abc", 0),
		memcmp("abc", "abc", 0));
	printf("Custom: %d | Standard: %d\n", ft_memcmp("abc", "ab", 3),
		memcmp("abc", "ab", 3));
	printf("Custom: %d | Standard: %d\n", ft_memcmp("", "", 1), memcmp("", "",
			1));
	return (0);
}
*/