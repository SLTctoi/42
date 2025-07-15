/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:10:10 by mchrispe          #+#    #+#             */
/*   Updated: 2025/07/15 12:14:07 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_and_print_move(t_img *img)
{
	img->count_move++;
	ft_printf("Nombre de mouvement : %i\n", img->count_move);
}

int	ber_extension(char *filename)
{
	int	i;

	if (!filename)
		return (0);
	i = 0;
	while (filename[i])
		i++;
	if (i < 4)
		return (0);
	if (filename[i - 4] == '.' && filename[i - 3] == 'b' && filename[i
			- 2] == 'e' && filename[i - 1] == 'r')
		return (1);
	return (0);
}

int	count_item(t_img *img)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (img->map[y])
	{
		x = 0;
		while (img->map[y][x])
		{
			if (img->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	draw_tile(t_img *img, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(img->mlx, img->win, img->img_wall, x
			* img->img_width, y * img->img_height);
	else if (tile == '0')
		mlx_put_image_to_window(img->mlx, img->win, img->img_floor, x
			* img->img_width, y * img->img_height);
	else if (tile == 'P')
		mlx_put_image_to_window(img->mlx, img->win, img->img_player, x
			* img->img_width, y * img->img_height);
	else if (tile == 'C')
		mlx_put_image_to_window(img->mlx, img->win, img->img_item, x
			* img->img_width, y * img->img_height);
	else if (tile == 'E' || tile == 'W')
		mlx_put_image_to_window(img->mlx, img->win, img->img_exit, x
			* img->img_width, y * img->img_height);
}
