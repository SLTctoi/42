/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:10:10 by mchrispe          #+#    #+#             */
/*   Updated: 2025/07/16 14:45:11 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
#include "stdio.h"

void	map_valid_char(t_img *img)
{
	int	i;
	int	j;

	if (!img)
		return ;
	i = 0;
	while (img->map[i])
	{
		j = 0;
		while (img->map[i][j])
		{
			printf("%c ",img->map[i][j]);
			if (img->map[i][j] != '1' || img->map[i][j] != 'E'
				|| img->map[i][j] != 'P' || img->map[i][j] != '0'
				|| img->map[i][j] != 'C')
			{
				write(2, "Error: Use only E, P, C, 1 or 0.\n", 33);
				final_free(img->map);
				exit(0);
			}
			j++;
		}
		i++;
	}
}
