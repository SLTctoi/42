/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:59:31 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/09 18:22:09 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Vérifie si un caractère est un délimiteur
int	ft_is_delim(char ch, const char *delims)
{
	while (*delims)
	{
		if (ch == *delims)
			return (1);
		delims++;
	}
	return (0);
}

// Compte le nombre de mots dans une chaîne en tenant compte des guillemets
int	ft_word_count(const char *s, const char *delims)
{
	int		count;
	int		in_word;
	char	quote;

	count = 0;
	in_word = 0;
	quote = 0;
	while (*s)
	{
		if (!quote && (*s == '"' || *s == '\''))
			quote = *s;
		else if (quote && *s == quote)
			quote = 0;
		if (!ft_is_delim(*s, delims) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if ((ft_is_delim(*s, delims) && !quote) || (!*s))
			in_word = 0;
		s++;
	}
	return (count);
}

// Duplique les len premiers caractères d'une chaîne
char	*ft_strndup(const char *s, int len)
{
	char	*str;
	int		i;

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_free_all(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

const char	*ft_advance_delim(const char *s, const char *delims)
{
	while (*s && ft_is_delim(*s, delims))
		s++;
	return (s);
}
