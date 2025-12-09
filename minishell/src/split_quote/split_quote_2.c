/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:58:05 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/09 18:22:09 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Extrait le prochain mot d'une chaîne en gérant les guillemets
char	*ft_get_next_word(const char **s, const char *delims)
{
	const char	*start;
	char		quote;
	char		*word;

	quote = 0;
	*s = ft_advance_delim(*s, delims);
	start = *s;
	while (**s && (!ft_is_delim(**s, delims) || quote))
	{
		if (!quote && (**s == '"' || **s == '\''))
			quote = **s;
		else if (quote && **s == quote)
			quote = 0;
		(*s)++;
	}
	if (*s > start)
	{
		word = ft_strndup(start, *s - start);
		if (!word)
			return (NULL);
		return (word);
	}
	return (NULL);
}

// Split une chaîne selon des délimiteurs en respectant les guillemets
char	**ft_split_quote(const char *s, const char *delims)
{
	char	**res;
	int		i;
	int		wc;
	char	*word;

	if (!s || !delims)
		return (NULL);
	wc = ft_word_count(s, delims);
	res = malloc(sizeof(char *) * (wc + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < wc)
	{
		word = ft_get_next_word(&s, delims);
		if (!word)
		{
			ft_free_all(res, i - 1);
			return (NULL);
		}
		res[i++] = word;
	}
	res[i] = NULL;
	return (res);
}
