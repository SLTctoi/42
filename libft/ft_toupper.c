/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:35:53 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:36:20 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    printf("Custom: %c | Standard: %c\n", ft_toupper('a'), toupper('a'));
    printf("Custom: %c | Standard: %c\n", ft_toupper('z'), toupper('z'));
    printf("Custom: %c | Standard: %c\n", ft_toupper('A'), toupper('A'));
    printf("Custom: %c | Standard: %c\n", ft_toupper('Z'), toupper('Z'));
    printf("Custom: %c | Standard: %c\n", ft_toupper('1'), toupper('1'));
    printf("Custom: %c | Standard: %c\n", ft_toupper('!'), toupper('!'));
    printf("Custom: %c | Standard: %c\n", ft_toupper(' '), toupper(' '));

    return 0;
}
*/