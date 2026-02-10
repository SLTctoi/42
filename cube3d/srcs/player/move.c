/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:22:29 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:22:42 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y + game->player.dir_y * MOVE_SPEED;
	if (game->map.map[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map.map[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x
		- game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y
		- game->player.dir_y * MOVE_SPEED;
	if (game->map.map[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map.map[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}

void	strafe_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x
		- game->player.plane_x * MOVE_SPEED;
	new_y = game->player.pos_y
		- game->player.plane_y * MOVE_SPEED;
	if (game->map.map[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map.map[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}

void	strafe_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x
		+ game->player.plane_x * MOVE_SPEED;
	new_y = game->player.pos_y
		+ game->player.plane_y * MOVE_SPEED;
	if (game->map.map[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map.map[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}

void	rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_a;
	double	sin_a;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	cos_a = cos(angle);
	sin_a = sin(angle);
	player->dir_x = player->dir_x * cos_a - player->dir_y * sin_a;
	player->dir_y = old_dir_x * sin_a + player->dir_y * cos_a;
	player->plane_x = player->plane_x * cos_a - player->plane_y * sin_a;
	player->plane_y = old_plane_x * sin_a + player->plane_y * cos_a;
}
