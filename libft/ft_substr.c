/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:06:35 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/18 14:12:18 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*alloc_empty_string(void)
{
	char	*empty;

	empty = malloc(sizeof(char));
	if (empty)
		empty[0] = '\0';
	return (empty);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (alloc_empty_string());
	if (len > s_len - start)
		len = s_len - start;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    char *result;

    result = ft_substr("Hello, world!", 0, 5);
    printf("Custom: '%s'\n", result);
    free(result);

    result = ft_substr("Hello, world!", 7, 5);
    printf("Custom: '%s'\n", result);
    free(result);

    result = ft_substr("Hello, world!", 13, 5);
    printf("Custom: '%s'\n", result);
    free(result);

    result = ft_substr("Hello, world!", 0, 20);
    printf("Custom: '%s'\n", result);
    free(result);

    result = ft_substr("", 0, 5);
    printf("Custom: '%s'\n", result);
    free(result);

    result = ft_substr("Hello, world!", 20, 5);
    printf("Custom: '%s'\n", result);
    free(result);

    return 0;
}
*/