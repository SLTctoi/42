/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:18:32 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/28 13:20:53 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	if (needle_len > len)
		return (NULL);
	i = 0;
	while (haystack[i] != '\0' && i + needle_len <= len)
	{
		if (haystack[i] == needle[0] && ft_strncmp(haystack + i, needle,
				needle_len) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    printf("Custom: %s | Standard: %s\n", ft_strnstr("Hello, world!",
	"world", 13), strnstr("Hello, world!", "world", 13));
    printf("Custom: %s | Standard: %s\n", ft_strnstr("Hello, world!",
	"planet", 13), strnstr("Hello, world!", "planet", 13));
    printf("Custom: %s | Standard: %s\n", ft_strnstr("Hello, world!",
	"Hello", 5), strnstr("Hello, world!", "Hello", 5));
    printf("Custom: %s | Standard: %s\n", ft_strnstr("Hello, world!",
	"world", 5), strnstr("Hello, world!", "world", 5));
    printf("Custom: %s | Standard: %s\n", ft_strnstr("", "world", 0),
	strnstr("", "world", 0));
    printf("Custom: %s | Standard: %s\n", ft_strnstr("Hello, world!", "", 13),
	strnstr("Hello, world!", "", 13));

    return 0;
}
*/
