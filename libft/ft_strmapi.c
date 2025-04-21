/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:44:02 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:44:17 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	if (!s || !f)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
#include <stdlib.h>
char to_uppercase(unsigned int index, char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 'a' + 'A');
    return c;
}

int main(void)
{
    char *result;

    result = ft_strmapi("Hello, world!", to_uppercase);
    printf("Custom: %s\n", result);
    free(result);

    result = ft_strmapi("42Cursus", to_uppercase);
    printf("Custom: %s\n", result);
    free(result);

    result = ft_strmapi("", to_uppercase);
    printf("Custom: %s\n", result);
    free(result);

    return 0;
}
*/