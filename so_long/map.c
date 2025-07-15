/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:09:54 by mchrispe          #+#    #+#             */
/*   Updated: 2025/07/15 14:21:12 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_img *img, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			draw_tile(img, map[y][x], x, y);
			x++;
		}
		y++;
	}
}

int	resize_window(t_img *img)
{
	draw_map(img, img->map);
	return (0);
}

void	is_rectangular(t_img *img)
{
	size_t	len;
	int		i;
	int		ok;

	ok = 1;
	len = ft_strlen(img->map[0]);
	i = 1;
	while (img->map[i])
	{
		if (ft_strlen(img->map[i]) != len)
			ok = 0;
		i++;
	}
	if (!ok)
	{
		write(2, "Error: The map is incorrect.\n", 30);
		close_window(img);
	}
}
void	map_border(t_img *img)
{
	int	y;
	int	x;

	x = 0;
	while (x < img->map_height)
	{
		y = 0;
		while (y < img->map_width)
		{
			if (x == 0 && img->map[x][y] != '1')
				error_map_border(img);
			if (x == (img->map_height - 1) && img->map[x][y] != '1')
				error_map_border(img);
			if (y == 0 && img->map[x][y] != '1')
				error_map_border(img);
			if (y == (img->map_width - 1) && img->map[x][y] != '1')
				error_map_border(img);
			y++;
		}
		x++;
	}
}
