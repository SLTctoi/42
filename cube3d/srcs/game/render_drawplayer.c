/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_drawplayer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:57:16 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:57:21 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_player(t_game *game)
{
	int	offset_x;
	int	offset_y;
	int	x;
	int	y;

	offset_x = (SCREEN_WIDTH - map_width(game)) / 2;
	offset_y = (SCREEN_HEIGHT - map_height(game)) / 2;
	x = offset_x + game->player.pos_x * TILE_SIZE;
	y = offset_y + game->player.pos_y * TILE_SIZE;
	draw_square(game, x - 3, y - 3, 0xFF0000);
}
