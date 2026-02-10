/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:34:47 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:44:31 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	open_file(char *arg, t_map *map)
{
	size_t	arg_len;
	int		fd;

	arg_len = ft_strlen(arg);
	if (arg_len < 4
		|| ft_strncmp(arg + arg_len - 4, ".cub", 4) != 0)
		exit_error(ERROR_CUB_EXT, map);
	fd = open(arg, O_RDONLY);
	map->fd = fd;
	if (fd == -1)
		exit_error(NULL, map);
	return (fd);
}

void	init_map_struct(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f_set = 0;
	map->c_set = 0;
	map->map = NULL;
	map->fd = -1;
	map->gnl_buffer = NULL;
	map->tmp_identifier = NULL;
	map->tmp_value = NULL;
	map->current_line = NULL;
	map->tmp_split = NULL;
}

void	parse_error_exit(t_map *map, t_gnl_ctx *ctx, char *line)
{
	if (line)
		free(line);
	if (map->fd != -1)
		close(map->fd);
	free_map(map);
	free(ctx->buffer);
	exit(1);
}

void	init_parse_ctx(t_map *map, t_gnl_ctx *ctx, int fd)
{
	ctx->fd = fd;
	ctx->buffer = NULL;
	init_map_struct(map);
	map->fd = fd;
}

t_map	parse_entry_file(int fd)
{
	t_map		map;
	t_gnl_ctx	ctx;
	char		*str;
	int			map_started;

	map_started = 0;
	init_parse_ctx(&map, &ctx, fd);
	str = get_next_line(ctx.fd, &ctx.buffer, &map);
	map.gnl_buffer = ctx.buffer;
	while (str)
	{
		map.current_line = str;
		if (process_file_line(str, &map_started, &map, &ctx))
			parse_error_exit(&map, &ctx, str);
		free(str);
		map.current_line = NULL;
		str = get_next_line(ctx.fd, &ctx.buffer, &map);
		map.gnl_buffer = ctx.buffer;
	}
	free(ctx.buffer);
	return (map);
}
