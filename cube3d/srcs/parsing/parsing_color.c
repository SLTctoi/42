/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:32:48 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:37:29 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	count_csv_parts(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static int	parse_rgb_part(char *part, int *out, t_map *map)
{
	char	*trimmed;
	int		len;

	trimmed = ft_strtrim(part, WHITESPACES);
	if (!trimmed)
		exit_error(ERROR_MALLOC, map);
	if (!is_valid_number(trimmed))
	{
		free(trimmed);
		exit_error(ERROR_RGB_NOT_NUMBER, map);
	}
	len = ft_strlen(trimmed);
	if (len > 3)
	{
		free(trimmed);
		exit_error(ERROR_RGB_TOO_LARGE, map);
	}
	*out = ft_atoi(trimmed);
	free(trimmed);
	if (*out < 0 || *out > 255)
		exit_error(ERROR_RGB_OUT_OF_RANGE, map);
	return (0);
}

int	parse_rgb(char *value, int rgb[3], t_map *map)
{
	char	**split;
	int		i;

	split = ft_split(value, ",");
	if (!split)
		exit_error(ERROR_MALLOC, map);
	map->tmp_split = split;
	if (count_csv_parts(split) != 3)
	{
		free_token(split);
		map->tmp_split = NULL;
		exit_error(ERROR_RGB_COUNT, map);
	}
	i = -1;
	while (++i < 3)
		parse_rgb_part(split[i], &rgb[i], map);
	free_token(split);
	map->tmp_split = NULL;
	return (0);
}

int	assign_color_value(char *identifier, char *value, t_map *map)
{
	if (!ft_strcmp(identifier, "F"))
	{
		if (map->f_set)
			return (1);
		parse_rgb(value, map->f, map);
		map->f_set = 1;
	}
	else if (!ft_strcmp(identifier, "C"))
	{
		if (map->c_set)
			return (1);
		parse_rgb(value, map->c, map);
		map->c_set = 1;
	}
	return (0);
}

char	*extract_color_value(char *line, int *pos, t_map *map)
{
	int		start;

	while (ft_iswhitespace(line[*pos]))
		(*pos)++;
	if (!line[*pos])
		exit_error(ERROR_LINE_FORMAT, map);
	start = *pos;
	while (line[*pos] && line[*pos] != '\n')
		(*pos)++;
	return (ft_substr(line, start, *pos - start));
}
