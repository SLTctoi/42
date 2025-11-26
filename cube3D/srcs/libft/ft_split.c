/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:05:07 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/26 00:19:08 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_delimiter(char c, char *delim)
{
	int	i;

	i = 0;
	while (delim[i])
	{
		if (c == delim[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_word_count(const char *s, char *delim)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (!is_delimiter(*s, delim) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_delimiter(*s, delim))
			in_word = 0;
		s++;
	}
	return (count);
}

char	*ft_strndup(const char *s, int len)
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

char	**ft_split(const char *s, char *delim)
{
	char	**result;

	if (!s || !delim)
		return (NULL);
	result = malloc(sizeof(char *) * (ft_word_count(s, delim) + 1));
	if (!result)
		return (NULL);
	if (!ft_fill_result(result, s, delim))
		return (NULL);
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
