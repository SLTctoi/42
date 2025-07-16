/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:10:19 by mchrispe          #+#    #+#             */
/*   Updated: 2025/07/16 10:28:19 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	recurse_down(t_flood *f, int x, int y)
{
	int	new_y;

	new_y = y + 1;
	if (new_y >= f->map_h || f->visited[new_y][x])
		return ;
	if (f->map[new_y][x] == '1')
		return ;
	f->visited[new_y][x] = 1;
	if (f->map[new_y][x] == 'C')
		f->items_found++;
	if (f->map[new_y][x] == 'E')
		f->exit_found = 1;
	recurse_up(f, x, new_y);
	recurse_down(f, x, new_y);
	recurse_left(f, x, new_y);
	recurse_right(f, x, new_y);
}

void	recurse_left(t_flood *f, int x, int y)
{
	int	new_x;

	new_x = x - 1;
	if (new_x < 0 || f->visited[y][new_x])
		return ;
	if (f->map[y][new_x] == '1')
		return ;
	f->visited[y][new_x] = 1;
	if (f->map[y][new_x] == 'C')
		f->items_found++;
	if (f->map[y][new_x] == 'E')
		f->exit_found = 1;
	recurse_up(f, new_x, y);
	recurse_down(f, new_x, y);
	recurse_left(f, new_x, y);
	recurse_right(f, new_x, y);
}

void	recurse_right(t_flood *f, int x, int y)
{
	int	new_x;

	new_x = x + 1;
	if (new_x >= f->map_w || f->visited[y][new_x])
		return ;
	if (f->map[y][new_x] == '1')
		return ;
	f->visited[y][new_x] = 1;
	if (f->map[y][new_x] == 'C')
		f->items_found++;
	if (f->map[y][new_x] == 'E')
		f->exit_found = 1;
	recurse_up(f, new_x, y);
	recurse_down(f, new_x, y);
	recurse_left(f, new_x, y);
	recurse_right(f, new_x, y);
}

int	get_map_width(char **map)
{
	int	x;

	x = 0;
	if (!map || !map[0])
		return (0);
	while (map[0][x] != '\0')
		x++;
	return (x);
}

int	get_map_height(char **map)
{
	int	y;

	y = 0;
	if (!map)
		return (0);
	while (map[y] != NULL)
		y++;
	return (y);
}
