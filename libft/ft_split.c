/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:05:07 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/18 11:05:26 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_word_count(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, int len)
{
	char	*str;
	int		i;

	str = malloc(len + 1);
	i = 0;
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char		**result;
	int			i;
	const char	*start;

	i = 0;
	result = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!s || !result)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		if (s > start)
		{
			result[i] = ft_strndup(start, s - start);
			if (!result[i])
				return (NULL);
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	**result;
	size_t	i;

	result = ft_split("Hello world 42", ' ');
	for (i = 0; result[i]; i++)
		printf("Custom: %s\n", result[i]);
	for (i = 0; result[i]; i++)
		free(result[i]);
	free(result);
	result = ft_split(",,,42,,,cursus,,,", ',');
	for (i = 0; result[i]; i++)
		printf("Custom: %s\n", result[i]);
	for (i = 0; result[i]; i++)
		free(result[i]);
	free(result);
	result = ft_split("", ',');
	for (i = 0; result[i]; i++)
		printf("Custom: %s\n", result[i]);
	for (i = 0; result[i]; i++)
		free(result[i]);
	free(result);
	result = ft_split("42", ' ');
	for (i = 0; result[i]; i++)
		printf("Custom: %s\n", result[i]);
	for (i = 0; result[i]; i++)
		free(result[i]);
	free(result);
	return (0);
}
*/
