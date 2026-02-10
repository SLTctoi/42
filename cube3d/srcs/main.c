/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:14:21 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/09 13:30:20 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_keys(t_keys *keys)
{
	keys->w = 0;
	keys->s = 0;
	keys->a = 0;
	keys->d = 0;
	keys->left = 0;
	keys->right = 0;
}

static void	init_game(t_game *game, char *map_file)
{
	int	fd;

	ft_bzero(game, sizeof(*game));
	init_map_struct(&game->map);
	fd = open_file(map_file, &game->map);
	game->map = parse_entry_file(fd);
	if (game->map.fd != -1)
		close(game->map.fd);
	validate_all_elements(&game->map);
	textures_is_valid(&game->map);
	validate_player_count(&game->map);
	validate_map_closed(&game->map);
	validate_map_spaces(&game->map);
	init_player(&game->map, &game->player);
}

static void	init_graphics(t_game *game)
{
	init_mlx(game);
	load_textures(game);
	init_keys(&game->keys);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_error(ERROR_USAGE, NULL);
	init_game(&game, argv[1]);
	init_graphics(&game);
	free_map(&game.map);
	return (0);
}
