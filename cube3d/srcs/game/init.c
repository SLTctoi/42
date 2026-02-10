/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:54:23 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/09 13:33:26 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	render_frame(t_game *game)
{
	if (game->keys.w)
		move_forward(game);
	if (game->keys.s)
		move_backward(game);
	if (game->keys.a)
		strafe_left(game);
	if (game->keys.d)
		strafe_right(game);
	if (game->keys.left)
		rotate_player(&game->player, -ROT_SPEED);
	if (game->keys.right)
		rotate_player(&game->player, ROT_SPEED);
	ft_bzero(game->screen.addr,
		SCREEN_HEIGHT * game->screen.line_len);
	draw_map(game);
	draw_player(game);
	cast_rays(game);
	mlx_put_image_to_window(game->mlx,
		game->win,
		game->screen.img_ptr,
		0, 0);
	return (0);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(ERROR_MLX_INIT, &game->map);
	game->win = mlx_new_window(game->mlx,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			"cub3D");
	if (!game->win)
		exit_error("Error: Window creation failed\n", &game->map);
	game->screen.img_ptr = mlx_new_image(game->mlx,
			SCREEN_WIDTH,
			SCREEN_HEIGHT);
	if (!game->screen.img_ptr)
		exit_error("Error: Image creation failed\n", &game->map);
	game->screen.addr = mlx_get_data_addr(game->screen.img_ptr,
			&game->screen.bpp,
			&game->screen.line_len,
			&game->screen.endian);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W)
		game->keys.w = 1;
	else if (keycode == KEY_S)
		game->keys.s = 1;
	else if (keycode == KEY_A)
		game->keys.a = 1;
	else if (keycode == KEY_D)
		game->keys.d = 1;
	else if (keycode == KEY_LEFT)
		game->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = 0;
	else if (keycode == KEY_S)
		game->keys.s = 0;
	else if (keycode == KEY_A)
		game->keys.a = 0;
	else if (keycode == KEY_D)
		game->keys.d = 0;
	else if (keycode == KEY_LEFT)
		game->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 0;
	return (0);
}

int	close_window(t_game *game)
{
	if (game->tex_no.img)
		mlx_destroy_image(game->mlx, game->tex_no.img);
	if (game->tex_so.img)
		mlx_destroy_image(game->mlx, game->tex_so.img);
	if (game->tex_we.img)
		mlx_destroy_image(game->mlx, game->tex_we.img);
	if (game->tex_ea.img)
		mlx_destroy_image(game->mlx, game->tex_ea.img);
	if (game->screen.img_ptr)
		mlx_destroy_image(game->mlx, game->screen.img_ptr);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free_map(&game->map);
	exit(0);
	return (0);
}
