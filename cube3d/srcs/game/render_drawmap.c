/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_drawmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:56:12 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:56:23 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_width(t_game *game)
{
	int	row;
	int	max;

	row = 0;
	max = 0;
	while (game->map.map[row])
	{
		if ((int)ft_strlen(game->map.map[row]) > max)
			max = ft_strlen(game->map.map[row]);
		row++;
	}
	return (max * TILE_SIZE);
}

int	map_height(t_game *game)
{
	return (count_map_lines(game->map.map) * TILE_SIZE);
}

void	draw_map(t_game *game)
{
	int	row;
	int	col;
	int	offset_x;
	int	offset_y;

	offset_x = (SCREEN_WIDTH - map_width(game)) / 2;
	offset_y = (SCREEN_HEIGHT - map_height(game)) / 2;
	row = 0;
	while (game->map.map[row])
	{
		col = 0;
		while (game->map.map[row][col])
		{
			if (game->map.map[row][col] == '1')
				draw_square(game,
					offset_x + col * TILE_SIZE,
					offset_y + row * TILE_SIZE,
					0xFFFFFF);
			col++;
		}
		row++;
	}
}
