/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:40:33 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/18 13:10:27 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Custom: %d | Standard: %d\n", ft_strncmp("Hello, world!",
	"Hello, universe!", 7), strncmp("Hello, world!", "Hello, universe!", 7));
    printf("Custom: %d | Standard: %d\n", ft_strncmp("Hello, world!",
	"Hello, universe!", 13), strncmp("Hello, world!", "Hello, universe!", 13));
    printf("Custom: %d | Standard: %d\n", ft_strncmp("Hello, world!",
	"Hello, world!", 13), strncmp("Hello, world!", "Hello, world!", 13));
    printf("Custom: %d | Standard: %d\n", ft_strncmp("Test", "Tester", 4),
	strncmp("Test", "Tester", 4));
    printf("Custom: %d | Standard: %d\n", ft_strncmp("Test", "Tester", 5),
	strncmp("Test", "Tester", 5));
    printf("Custom: %d | Standard: %d\n", ft_strncmp("", "", 1),
	strncmp("", "", 1));

    return 0;
}
*/