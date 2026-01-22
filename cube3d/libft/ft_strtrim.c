/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:41:40 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:42:31 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	len = end - start;
	trim = (char *)malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, s1 + start, len + 1);
	return (trim);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    char *result;

    result = ft_strtrim("   Hello, world!   ", " ");
    printf("Custom: '%s'\n", result);
    free(result);

    result = ft_strtrim("xxxHello, world!xxx", "x");
    printf("Custom: '%s'\n", result);
    free(result);

    result = ft_strtrim("Hello, world!", "x");
    printf("Custom: '%s'\n", result);
    free(result);

    result = ft_strtrim("", "x");
    printf("Custom: '%s'\n", result);
    free(result);

    result = ft_strtrim("   ", " ");
    printf("Custom: '%s'\n", result);
    free(result);

    return 0;
}
*/