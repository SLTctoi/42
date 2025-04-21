/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:20:06 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 12:20:29 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("Custom: %s | Standard: %s\n", ft_strchr("Hello, world!", 'o'),
		strchr("Hello, world!", 'o'));
	printf("Custom: %s | Standard: %s\n", ft_strchr("Hello, world!", 'z'),
		strchr("Hello, world!", 'z'));
	printf("Custom: %s | Standard: %s\n", ft_strchr("Hello, world!", '\0'),
		strchr("Hello, world!", '\0'));
	printf("Custom: %s | Standard: %s\n", ft_strchr("", 'a'), strchr("", 'a'));
	printf("Custom: %s | Standard: %s\n", ft_strchr("42", '2'), strchr("42",
			'2'));
	return (0);
}
*/