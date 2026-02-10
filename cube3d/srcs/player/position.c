/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:23:00 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:24:27 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_dir_plane(char c, t_player *p)
{
	if (c == 'N')
		dir_north(p);
	else if (c == 'S')
		dir_south(p);
	else if (c == 'E')
		dir_east(p);
	else if (c == 'W')
		dir_west(p);
}

void	set_player_position(t_player *player, int row, int col, char dir)
{
	player->pos_x = col + 0.5;
	player->pos_y = row + 0.5;
	set_dir_plane(dir, player);
}

int	search_row(t_map *map, t_player *player, int row)
{
	int	col;

	col = 0;
	while (map->map[row][col])
	{
		if (map->map[row][col] == 'N' || map->map[row][col] == 'S' ||
			map->map[row][col] == 'E' || map->map[row][col] == 'W')
		{
			set_player_position(player, row, col, map->map[row][col]);
			map->map[row][col] = '0';
			return (1);
		}
		col++;
	}
	return (0);
}

void	init_player(t_map *map, t_player *player)
{
	int	row;
	int	found;

	row = 0;
	found = 0;
	while (map->map[row] && !found)
	{
		if (search_row(map, player, row))
			found = 1;
		row++;
	}
	if (!found)
		exit_error(ERROR_NO_PLAYER_START, map);
}
