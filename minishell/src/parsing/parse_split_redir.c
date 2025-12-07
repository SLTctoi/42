/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:35:00 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/07 14:04:06 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// compte le nombre de token
static int	count_total_tokens(char **tokens)
{
	int		count;
	int		i;
	char	**split;
	int		j;

	count = 0;
	i = 0;
	while (tokens[i])
	{
		split = split_redirections(tokens[i]);
		if (split)
		{
			j = 0;
			while (split[j])
			{
				count++;
				free(split[j++]);
			}
			free(split);
		}
		else
			count++;
		i++;
	}
	return (count);
}

// on ajoute token dans result
static int	add_token_or_split(char **result, int *r_idx, char *token)
{
	char	**split;
	int		j;

	split = split_redirections(token);
	if (split)
	{
		j = 0;
		while (split[j])
			result[(*r_idx)++] = split[j++];
		free(split);
	}
	else
	{
		result[(*r_idx)] = ft_strdup(token);
		if (!result[(*r_idx)])
			return (0);
		(*r_idx)++;
	}
	return (1);
}

// alloue un tab en fonction du nombre de token
char	**expand_redirect_tokens(char **tokens)
{
	char	**result;
	int		count;
	int		i;
	int		r_idx;

	if (!tokens)
		return (NULL);
	count = count_total_tokens(tokens);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = -1;
	r_idx = 0;
	while (tokens[++i])
	{
		if (!add_token_or_split(result, &r_idx, tokens[i]))
		{
			while (r_idx > 0)
				free(result[--r_idx]);
			free(result);
			return (NULL);
		}
	}
	result[r_idx] = NULL;
	return (result);
}
