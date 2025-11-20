/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe < mchrispe@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:19:48 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/22 10:20:43 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	while (s[i])
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	const char	*str1 = "Hello, world!";
	char		*dup_custom;
	char		*dup_standard;

	dup_custom = ft_strdup(str1);
	dup_standard = strdup(str1);
	printf("Original : %s\n", str1);
	printf("Custom   : %s\n", dup_custom);
	printf("Standard : %s\n", dup_standard);
	// Libérer la mémoire allouée
	free(dup_custom);
	free(dup_standard);
	return (0);
}
*/
