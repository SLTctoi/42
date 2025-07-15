/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:09:25 by mchrispe          #+#    #+#             */
/*   Updated: 2025/07/15 13:19:59 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	final_free(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	exit_victory(t_img *img)
{
	write(1, "Bravo, vous avez gagné !\n", 26);
	close_window(img);
}

int	close_window(t_img *img)
{
	if (img->map)
		final_free(img->map);
	if (img->win)
		mlx_destroy_window(img->mlx, img->win);
	if (img->img_wall)
		mlx_destroy_image(img->mlx, img->img_wall);
	if (img->img_player)
		mlx_destroy_image(img->mlx, img->img_player);
	if (img->img_item)
		mlx_destroy_image(img->mlx, img->img_item);
	if (img->img_exit)
		mlx_destroy_image(img->mlx, img->img_floor);
	if (img->img_floor)
		mlx_destroy_image(img->mlx, img->img_exit);
	if (img->mlx)
	{
		mlx_destroy_display(img->mlx);
		free(img->mlx);
	}
	exit(0);
}
void	error_map_border(t_img *img)
{
	write(2, "Error: Border problem detected. Out of bounds access!\n", 54);
	close_window(img);
}
