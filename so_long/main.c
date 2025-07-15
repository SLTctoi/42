/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:09:51 by mchrispe          #+#    #+#             */
/*   Updated: 2025/07/15 12:58:37 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_and_prepare_map(t_img *img, char *filename)
{
	if (!ber_extension(filename))
	{
		write(2, "Error: ./so_long map.ber\n", 26);
		return (1);
	}
	img->map = parse_map(filename);
	if (!img->map)
	{
		write(2, "Error: Failed to load map\n", 27);
		return (1);
	}
	init_player_pos(img);
	init_exit_pos(img);
	img->map_width = get_map_width(img->map);
	img->map_height = get_map_height(img->map);
	return (0);
}

int	validate_map(t_img *img)
{
	if (!check_map_access(img))
	{
		write(2, "Error: Map is not solvable\n", 27);
		final_free(img->map);
		return (1);
	}
	if (count_exit(img) != 1 || count_player(img) != 1 || img->total_items < 1)
	{
		write(2, "exactly 1 exit (E),and at least 1 collectible (C).\n", 52);
		final_free(img->map);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_img	img;

	if (ac != 2)
	{
		write(2, "Error: ./so_long map.ber\n", 26);
		return (1);
	}
	if (load_and_prepare_map(&img, av[1]))
		return (1);
	if (validate_map(&img))
		return (1);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.map_width * 64, img.map_height * 64,
			"So_long");
	load_img(&img);
	is_rectangular(&img);
	map_border(&img);
	draw_map(&img, img.map);
	mlx_hook(img.win, 17, 0, close_window, &img);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_expose_hook(img.win, resize_window, &img);
	mlx_loop(img.mlx);
	final_free(img.map);
	return (0);
}
