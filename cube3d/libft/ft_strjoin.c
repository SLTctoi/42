/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:05:39 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/18 11:06:00 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
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

    result = ft_strjoin("Hello, ", "world!");
    printf("Custom: %s\n", result);
    free(result);

    result = ft_strjoin("42", "Cursus");
    printf("Custom: %s\n", result);
    free(result);

    result = ft_strjoin("", "Test");
    printf("Custom: %s\n", result);
    free(result);

    result = ft_strjoin("Test", "");
    printf("Custom: %s\n", result);
    free(result);

    result = ft_strjoin("", "");
    printf("Custom: %s\n", result);
    free(result);

    return 0;
}
*/