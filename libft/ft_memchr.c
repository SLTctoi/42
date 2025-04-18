/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:54:25 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 12:54:49 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	uc;
	size_t			i;

	ptr = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == uc)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "Hello, world!";

	printf("Custom: %s | Standard: %s\n", (char *)memchr(str, 'w', 13),
		(char *)memchr(str, 'w', 13));
	printf("Custom: %s | Standard: %s\n", (char *)memchr(str, 'z', 13),
		(char *)memchr(str, 'z', 13));
	printf("Custom: %s | Standard: %s\n", (char *)memchr(str, 'o', 5),
		(char *)memchr(str, 'o', 5));
	printf("Custom: %s | Standard: %s\n", (char *)memchr(str, '\0', 13),
		(char *)memchr(str, '\0', 13));
	return (0);
}
*/