/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:33:39 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:51:19 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	trim_leading_isolated_ones(char *line)
{
	int	i;

	if (!has_isolated_ones_at_start(line))
		return ;
	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] == '1')
	{
		line[i] = ' ';
		i++;
	}
}

int	parse_map_line(char *line, t_map *map)
{
	if (!(map->no && map->so && map->we && map->ea
			&& map->f_set && map->c_set))
	{
		ft_putstr_fd(ERROR_MISSING_ELEMENTS, 2);
		return (1);
	}
	trim_leading_isolated_ones(line);
	check_map_chars(line, map);
	map->map = ft_realloc_map(map->map,
			count_map_lines(map->map), line, map);
	return (0);
}

int	parse_line(char *line, t_map *map, int map_started)
{
	if (!its_map(line))
		return (parse_non_map_line(line, map, map_started));
	return (parse_map_line(line, map));
}

void	check_empty_lines_after(char *str, int map_started,
			t_map *map, t_gnl_ctx *ctx)
{
	char	*next_str;
	int		i;

	if (!map_started)
		return ;
	next_str = get_next_line(ctx->fd, &ctx->buffer, map);
	while (next_str)
	{
		i = 0;
		while (ft_iswhitespace(next_str[i]))
			i++;
		if (next_str[i] != '\0')
		{
			free(next_str);
			free(str);
			free(ctx->buffer);
			ft_putstr_fd(ERROR_EMPTY_LINE_MAP, 2);
			exit(1);
		}
		free(next_str);
		next_str = get_next_line(ctx->fd, &ctx->buffer, map);
	}
}

int	process_file_line(char *str, int *map_started,
			t_map *map, t_gnl_ctx *ctx)
{
	int	i;

	i = skip_whitespace(str);
	if (str[i] == '\0')
	{
		check_empty_lines_after(str, *map_started,
			map, ctx);
		return (0);
	}
	if (its_map(str + i))
	{
		*map_started = 1;
		if (parse_line(str, map, *map_started) != 0)
			return (1);
	}
	else
	{
		if (parse_line(str + i, map, *map_started) != 0)
			return (1);
	}
	return (0);
}
