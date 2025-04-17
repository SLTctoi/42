/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:45:47 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/10 12:50:56 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	printf("Custom: %d | Standard: %d\n", ft_isalpha('a'), isalpha('a'));
	printf("Custom: %d | Standard: %d\n", ft_isalpha('Z'), isalpha('Z'));
	printf("Custom: %d | Standard: %d\n", ft_isalpha('1'), isalpha('1'));
	printf("Custom: %d | Standard: %d\n", ft_isalpha(' '), isalpha(' '));
	printf("Custom: %d | Standard: %d\n", ft_isalpha('z'), isalpha('z'));
	printf("Custom: %d | Standard: %d\n", ft_isalpha(0), isalpha(0));
	return 0;
}
*/
