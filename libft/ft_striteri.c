/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:44:39 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:44:54 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

void to_uppercase(unsigned int index, char *c)
{
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 'a' + 'A';
}

int main(void)
{
    char str1[] = "Hello, world!";
    char str2[] = "42Cursus";
    char str3[] = "";

    printf("Original: %s\n", str1);
    ft_striteri(str1, to_uppercase);
    printf("Modified: %s\n", str1);

    printf("Original: %s\n", str2);
    ft_striteri(str2, to_uppercase);
    printf("Modified: %s\n", str2);

    printf("Original: %s\n", str3);
    ft_striteri(str3, to_uppercase);
    printf("Modified: %s\n", str3);

    return 0;
}
*/