/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:26:39 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:27:41 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *str1 = "Hello, world!";
    const char *str2 = "42";
    const char *str3 = "";
    const char *str4 = "A longer string to test";

    printf("Custom: %zu | Standard: %zu\n", ft_strlen(str1), strlen(str1));
    printf("Custom: %zu | Standard: %zu\n", ft_strlen(str2), strlen(str2));
    printf("Custom: %zu | Standard: %zu\n", ft_strlen(str3), strlen(str3));
    printf("Custom: %zu | Standard: %zu\n", ft_strlen(str4), strlen(str4));

    return 0;
}
*/