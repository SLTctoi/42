/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:30:00 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/09 18:22:09 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	has_multiple_redirects(const char *str)
{
	int		redir_count;
	int		i;
	char	quote;

	redir_count = 0;
	i = 0;
	quote = 0;
	while (str[i])
	{
		if (!quote && (str[i] == '"' || str[i] == '\''))
			quote = str[i];
		else if (quote && str[i] == quote)
			quote = 0;
		else if (!quote && (str[i] == '<' || str[i] == '>'))
		{
			redir_count++;
			while (str[i] && (str[i] == '<' || str[i] == '>'))
				i++;
			if (redir_count > 1)
				return (1);
			continue ;
		}
		i++;
	}
	return (0);
}

static char	*extract_part(const char *str, int start, int len)
{
	char	*part;
	int		i;

	if (len <= 0)
		return (NULL);
	part = malloc(len + 1);
	if (!part)
		return (NULL);
	i = 0;
	while (i < len)
	{
		part[i] = str[start + i];
		i++;
	}
	part[i] = '\0';
	return (part);
}

static int	process_redirect(char **result, const char *str, int i, int *r_idx)
{
	int	start;

	start = i;
	while (str[i] && (str[i] == '<' || str[i] == '>'))
		i++;
	result[(*r_idx)++] = extract_part(str, start, i - start);
	return (i);
}

// start - 1 ou start ?
static int	add_parts(char **result, const char *str, int *r_idx)
{
	int		i;
	int		start;
	char	quote;

	i = -1;
	start = 0;
	quote = 0;
	while (str[++i])
	{
		if (!quote && (str[i] == '"' || str[i] == '\''))
			quote = str[i];
		else if (quote && str[i] == quote)
			quote = 0;
		else if (!quote && (str[i] == '<' || str[i] == '>'))
		{
			if (i > start)
				result[(*r_idx)++] = extract_part(str, start, i - start);
			start = process_redirect(result, str, i, r_idx);
			i = start - 1;
			continue ;
		}
	}
	if (i > start)
		result[(*r_idx)++] = extract_part(str, start, i - start);
	return (1);
}

char	**split_redirections(const char *token)
{
	char	**result;
	int		r_idx;

	if (!token || !token[0])
		return (NULL);
	if (!has_multiple_redirects(token))
		return (NULL);
	result = malloc(sizeof(char *) * 10);
	if (!result)
		return (NULL);
	r_idx = 0;
	add_parts(result, token, &r_idx);
	result[r_idx] = NULL;
	return (result);
}
