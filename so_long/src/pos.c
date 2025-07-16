/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:10:05 by mchrispe          #+#    #+#             */
/*   Updated: 2025/07/16 10:28:04 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_player_pos(t_img *img)
{
	int	y;
	int	x;

	y = 0;
	while (img->map[y])
	{
		x = 0;
		while (img->map[y][x])
		{
			if (img->map[y][x] == 'P')
			{
				img->player_x = x;
				img->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_exit_pos(t_img *img)
{
	int	y;
	int	x;

	y = 0;
	while (img->map[y])
	{
		x = 0;
		while (img->map[y][x])
		{
			if (img->map[y][x] == 'E')
			{
				img->exit_x = x;
				img->exit_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
