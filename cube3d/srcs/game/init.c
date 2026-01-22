/* header */

#include "cub3D.h"

int	render_frame(t_game *game)
{
	int	offset_x;
	int	offset_y;

	ft_bzero(game->screen.addr,
		SCREEN_HEIGHT * game->screen.line_len);

	offset_x = (SCREEN_WIDTH - map_width(game)) / 2;
	offset_y = (SCREEN_HEIGHT - map_height(game)) / 2;

	draw_map(game);
	draw_player(game);

	draw_line(game,
		offset_x + (int)(game->player.pos_x * TILE_SIZE),
		offset_y + (int)(game->player.pos_y * TILE_SIZE),
		offset_x + (int)((game->player.pos_x + game->player.dir_x * 0.5) * TILE_SIZE),
		offset_y + (int)((game->player.pos_y + game->player.dir_y * 0.5) * TILE_SIZE));
	
	cast_rays(game);

	mlx_put_image_to_window(game->mlx,
		game->win,
		game->screen.img_ptr,
		0, 0);
	return (0);
}

void init_mlx(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        exit_error("Error: MLX init failed\n", &game->map);

    game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
    if (!game->win)
        exit_error("Error: Window creation failed\n", &game->map);

    game->screen.img_ptr = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!game->screen.img_ptr)
        exit_error("Error: Image creation failed\n", &game->map);

    game->screen.addr = mlx_get_data_addr(game->screen.img_ptr,
        &game->screen.bpp, &game->screen.line_len, &game->screen.endian);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W)
		move_forward(game);
	else if (keycode == KEY_S)
		move_backward(game);
	else if (keycode == KEY_A)
		strafe_left(game);
	else if (keycode == KEY_D)
		strafe_right(game);
    else if (keycode == KEY_LEFT)
		rotate_player(&game->player, -ROT_SPEED);   // rotate left
	else if (keycode == KEY_RIGHT)
		rotate_player(&game->player, ROT_SPEED);  // rotate right


	printf("Player pos: (%.2f, %.2f) dir: (%.2f, %.2f)\n",
		game->player.pos_x,
		game->player.pos_y,
		game->player.dir_x,
		game->player.dir_y);
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
	free_map(&game->map);
	exit(0);
	return (0);
}

