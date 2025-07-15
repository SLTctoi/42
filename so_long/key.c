/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:09:47 by mchrispe          #+#    #+#             */
/*   Updated: 2025/07/15 12:36:36 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_img *img)
{
	if (keycode == 65307)
		close_window(img);
	if (keycode == 119 || keycode == 65362)
		move_up(img);
	else if (keycode == 115 || keycode == 65364)
		move_down(img);
	else if (keycode == 97 || keycode == 65361)
		move_left(img);
	else if (keycode == 100 || keycode == 65363)
		move_right(img);
	return (0);
}

void	move_up(t_img *img)
{
	int	x;
	int	y;

	x = img->player_x;
	y = img->player_y;
	if (img->map[y - 1][x] != '1')
	{
		img->map[y][x] = '0';
		y--;
		img->map[y][x] = 'P';
		img->player_y = y;
		draw_map(img, img->map);
		add_and_print_move(img);
	}
	if (x == img->exit_x && (y + 1) == img->exit_y)
	{
		img->map[y + 1][x] = 'E';
		draw_map(img, img->map);
	}
	if (img->exit_x == img->player_x && img->exit_y == img->player_y
		&& count_item(img) == 0)
		exit_victory(img);
}

void	move_down(t_img *img)
{
	int	x;
	int	y;

	x = img->player_x;
	y = img->player_y;
	if (img->map[y + 1][x] != '1')
	{
		img->map[y][x] = '0';
		y++;
		img->map[y][x] = 'P';
		img->player_y = y;
		draw_map(img, img->map);
		add_and_print_move(img);
	}
	if (x == img->exit_x && (y - 1) == img->exit_y)
	{
		img->map[y - 1][x] = 'E';
		draw_map(img, img->map);
	}
	if (img->exit_x == img->player_x && img->exit_y == img->player_y
		&& count_item(img) == 0)
		exit_victory(img);
}

void	move_left(t_img *img)
{
	int	x;
	int	y;

	x = img->player_x;
	y = img->player_y;
	if (img->map[y][x - 1] != '1')
	{
		img->map[y][x] = '0';
		x--;
		img->map[y][x] = 'P';
		img->player_x = x;
		draw_map(img, img->map);
		add_and_print_move(img);
	}
	if ((x + 1) == img->exit_x && y == img->exit_y)
	{
		img->map[y][x + 1] = 'E';
		draw_map(img, img->map);
	}
	if (img->exit_x == img->player_x && img->exit_y == img->player_y
		&& count_item(img) == 0)
		exit_victory(img);
}

void	move_right(t_img *img)
{
	int	x;
	int	y;

	x = img->player_x;
	y = img->player_y;
	if (img->map[y][x + 1] != '1')
	{
		img->map[y][x] = '0';
		x++;
		img->map[y][x] = 'P';
		img->player_x = x;
		draw_map(img, img->map);
		add_and_print_move(img);
	}
	if ((x - 1) == img->exit_x && y == img->exit_y)
	{
		img->map[y][x - 1] = 'E';
		draw_map(img, img->map);
	}
	if (img->exit_x == img->player_x && img->exit_y == img->player_y
		&& count_item(img) == 0)
		exit_victory(img);
}
