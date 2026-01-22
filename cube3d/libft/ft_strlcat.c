/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:14:14 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/18 11:48:25 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size <= dest_len)
		return (size + src_len);
	j = 0;
	i = dest_len;
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    char dest1[20] = "Hello";
    char dest2[20] = "Hello";
    char dest3[5] = "Hello";
    char dest4[20] = "";
    char dest5[20] = "Short";

    size_t result;

    result = ft_strlcat(dest1, " world!", 20);
    printf("Custom: %s | Return: %zu\n", dest1, result);

    result = ft_strlcat(dest2, " world!", 10);
    printf("Custom: %s | Return: %zu\n", dest2, result);

    result = ft_strlcat(dest3, " world!", 5);
    printf("Custom: %s | Return: %zu\n", dest3, result);

    result = ft_strlcat(dest4, "Test", 20);
    printf("Custom: %s | Return: %zu\n", dest4, result);

    result = ft_strlcat(dest5, " string", 7);
    printf("Custom: %s | Return: %zu\n", dest5, result);

    return 0;
}
*/