/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:36:51 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:37:17 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    printf("Custom: %c | Standard: %c\n", ft_tolower('A'), tolower('A'));
    printf("Custom: %c | Standard: %c\n", ft_tolower('Z'), tolower('Z'));
    printf("Custom: %c | Standard: %c\n", ft_tolower('a'), tolower('a'));
    printf("Custom: %c | Standard: %c\n", ft_tolower('z'), tolower('z'));
    printf("Custom: %c | Standard: %c\n", ft_tolower('1'), tolower('1'));
    printf("Custom: %c | Standard: %c\n", ft_tolower('!'), tolower('!'));
    printf("Custom: %c | Standard: %c\n", ft_tolower(' '), tolower(' '));

    return 0;
}
*/