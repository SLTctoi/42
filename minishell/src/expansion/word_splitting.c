/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_splitting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:00:00 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/04 17:43:10 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// compte le nombre de mots dans une chaine
int	count_words_ws(const char *s)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != ' ' && s[i] != '\t')
				i++;
		}
	}
	return (count);
}

// split une chaine sur les espaces et tabs
char	**split_on_whitespace(const char *s)
{
	char	**result;
	int		i;
	int		j;
	int		start;

	result = malloc(sizeof(char *) * (count_words_ws(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != ' ' && s[i] != '\t')
				i++;
			result[j++] = ft_strndup(s + start, i - start);
		}
	}
	result[j] = NULL;
	return (result);
}

// compte le nombre d'args dans un split
int	count_split_args(char **split)
{
	int	j;

	j = 0;
	while (split[j])
		j++;
	return (j);
}

// copie le split dans new_argv
int	copy_split_to_argv(char **new_argv, char **split, int k)
{
	int	j;

	j = 0;
	while (split[j])
		new_argv[k++] = split[j++];
	free(split);
	return (k);
}

// verifie si une chaine contient une variable non quotee
int	has_unquoted_variable(const char *s)
{
	int		in_single;
	int		in_double;
	int		i;

	in_single = 0;
	in_double = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (s[i] == '"' && !in_single)
			in_double = !in_double;
		else if (s[i] == '$' && !in_single && !in_double)
			return (1);
		i++;
	}
	return (0);
}
