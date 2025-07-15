/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:09:43 by mchrispe          #+#    #+#             */
/*   Updated: 2025/07/15 11:20:11 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_img *img)
{
	img->count_move = 0;
	img->img_width = 64;
	img->img_height = 64;
	img->img_wall = mlx_xpm_file_to_image(img->mlx,
			"img/greyBrick-Mangopunch.xpm", &img->img_width, &img->img_height);
	img->img_floor = mlx_xpm_file_to_image(img->mlx, "img/grass-Mangopunch.xpm",
			&img->img_width, &img->img_height);
	img->img_player = mlx_xpm_file_to_image(img->mlx, "img/skull007.xpm",
			&img->img_width, &img->img_height);
	img->img_exit = mlx_xpm_file_to_image(img->mlx, "img/portal.xpm",
			&img->img_width, &img->img_height);
	img->img_item = mlx_xpm_file_to_image(img->mlx, "img/coin.xpm",
			&img->img_width, &img->img_height);
}
