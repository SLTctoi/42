/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_extract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:33:17 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:33:19 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*extract_quoted_value(char *line, int *pos, t_map *map)
{
	char	*value;
	int		start;
	int		end;

	(*pos)++;
	start = *pos;
	while (line[*pos] && line[*pos] != '"')
		(*pos)++;
	if (!line[*pos])
		exit_error(ERROR_LINE_FORMAT, map);
	end = *pos;
	(*pos)++;
	value = ft_substr(line, start, end - start);
	return (value);
}

static char	*extract_unquoted_value(char *line, int *pos)
{
	char	*value;
	int		start;
	int		end;

	start = *pos;
	while (line[*pos] && !ft_iswhitespace(line[*pos]) && line[*pos] != '\n')
		(*pos)++;
	end = *pos;
	while (line[*pos] && ft_iswhitespace(line[*pos]) && line[*pos] != '\n')
		(*pos)++;
	value = ft_substr(line, start, end - start);
	return (value);
}

char	*extract_value_with_quotes(char *line, int *pos, t_map *map)
{
	char	*value;

	while (ft_iswhitespace(line[*pos]))
		(*pos)++;
	if (!line[*pos])
		exit_error(ERROR_LINE_FORMAT, map);
	if (line[*pos] == '"')
		value = extract_quoted_value(line, pos, map);
	else
		value = extract_unquoted_value(line, pos);
	return (value);
}

char	*extract_value_no_quotes(char *line, int *pos, t_map *map)
{
	char	*value;

	while (ft_iswhitespace(line[*pos]))
		(*pos)++;
	if (!line[*pos])
		exit_error(ERROR_LINE_FORMAT, map);
	if (line[*pos] == '"')
		exit_error(ERROR_LINE_FORMAT, map);
	value = extract_unquoted_value(line, pos);
	return (value);
}

char	*extract_identifier(char *line, int *pos)
{
	char	*identifier;
	int		start;

	*pos = 0;
	while (ft_iswhitespace(line[*pos]))
		(*pos)++;
	if (!line[*pos])
		return (NULL);
	start = *pos;
	while (line[*pos] && !ft_iswhitespace(line[*pos]))
		(*pos)++;
	identifier = ft_substr(line, start, *pos - start);
	return (identifier);
}
