/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:52:54 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:53:15 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ud;
	const unsigned char	*us;

	ud = (unsigned char *)dest;
	us = (const unsigned char *)src;
	if (us < ud && ud < us + n)
	{
		ud += n;
		us += n;
		while (n--)
			*--ud = *--us;
	}
	else
	{
		while (n--)
			*ud++ = *us++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest1[50] = "Hello, World!";
	char	dest2[50] = "Hello, World!";
	char	src[] = "42 Cursus";
	char	overlap1[50] = "Overlap Test";
	char	overlap2[50] = "Overlap Test";
	char	reverse1[50] = "Reverse Copy";
	char	reverse2[50] = "Reverse Copy";

	printf("Custom: %s | Standard: %s\n", (char *)ft_memmove(dest1 + 6, src, 9),
		(char *)memmove(dest2 + 6, src, 9));
	printf("Custom: %s | Standard: %s\n", (char *)ft_memmove(overlap1 + 3,
			overlap1, 7), (char *)memmove(overlap2 + 3, overlap2, 7));
	printf("Custom: %s | Standard: %s\n", (char *)ft_memmove(reverse1, reverse1
			+ 3, 7), (char *)memmove(reverse2, reverse2 + 3, 7));
	return (0);
}
*/