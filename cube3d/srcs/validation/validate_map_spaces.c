/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:18:36 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:20:34 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_walkable(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static void	check_adjacent(t_map *map, int y, int x)
{
	int	len;

	if (x > 0 && map->map[y][x - 1] == ' ')
		exit_error(ERROR_MAP_NOT_CLOSED_SPACE, map);
	len = ft_strlen(map->map[y]);
	if (x < len - 1 && map->map[y][x + 1] == ' ')
		exit_error(ERROR_MAP_NOT_CLOSED_SPACE, map);
	if (y > 0 && ((int)ft_strlen(map->map[y - 1]) <= x
			|| map->map[y - 1][x] == ' '))
		exit_error(ERROR_MAP_NOT_CLOSED_SPACE, map);
	if (map->map[y + 1] && ((int)ft_strlen(map->map[y + 1]) <= x
			|| map->map[y + 1][x] == ' '))
		exit_error(ERROR_MAP_NOT_CLOSED_SPACE, map);
}

void	validate_map_spaces(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (is_walkable(map->map[y][x]))
				check_adjacent(map, y, x);
			x++;
		}
		y++;
	}
}
