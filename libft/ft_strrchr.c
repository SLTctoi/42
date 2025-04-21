/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:33:00 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 12:33:28 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_c;

	last_c = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_c = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (last_c);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Custom: %s | Standard: %s\n", ft_strrchr("Hello, world!", 'o'), strrchr("Hello, world!", 'o'));
    printf("Custom: %s | Standard: %s\n", ft_strrchr("Hello, world!", 'z'), strrchr("Hello, world!", 'z'));
    printf("Custom: %s | Standard: %s\n", ft_strrchr("Hello, world!", '\0'), strrchr("Hello, world!", '\0'));
    printf("Custom: %s | Standard: %s\n", ft_strrchr("", 'a'), strrchr("", 'a'));
    printf("Custom: %s | Standard: %s\n", ft_strrchr("42", '2'), strrchr("42", '2'));

    return 0;
}
*/