/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:34:11 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/28 12:41:09 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst)
		return (ft_strlen(src));
	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    char dest1[20];
    char dest2[5];
    char dest3[20];
    char dest4[10];
    char dest5[20];

    size_t result;

    result = ft_strlcpy(dest1, "Hello, world!", 20);
    printf("Custom: %s | Return: %zu\n", dest1, result);

    result = ft_strlcpy(dest2, "Hello, world!", 5);
    printf("Custom: %s | Return: %zu\n", dest2, result);

    result = ft_strlcpy(dest3, "", 20);
    printf("Custom: %s | Return: %zu\n", dest3, result);

    result = ft_strlcpy(dest4, "Hello, world!", 10);
    printf("Custom: %s | Return: %zu\n", dest4, result);

    result = ft_strlcpy(dest5, "", 20);
    printf("Custom: %s | Return: %zu\n", dest5, result);

    return 0;
}
*/
