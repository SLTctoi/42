/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:18:54 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:18:55 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	validate_player_count(t_map *map)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (is_player(map->map[y][x]))
				count++;
			x++;
		}
		y++;
	}
	if (count == 0)
		exit_error(ERROR_NO_PLAYER, map);
	if (count > 1)
		exit_error(ERROR_MULTIPLE_PLAYERS, map);
}
