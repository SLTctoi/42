/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:10:15 by mchrispe          #+#    #+#             */
/*   Updated: 2025/07/16 10:28:13 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	**create_visited(int w, int h)
{
	int	**matrix;
	int	i;
	int	j;

	matrix = malloc(sizeof(int *) * h);
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < h)
	{
		matrix[i] = malloc(sizeof(int) * w);
		if (!matrix[i])
		{
			while (--i >= 0)
				free(matrix[i]);
			free(matrix);
			return (NULL);
		}
		j = 0;
		while (j < w)
			matrix[i][j++] = 0;
		i++;
	}
	return (matrix);
}

void	free_visited(int **matrix, int h)
{
	int	i;

	i = 0;
	while (i < h)
		free(matrix[i++]);
	free(matrix);
}

int	check_map_access(t_img *img)
{
	t_flood	flood;
	int		result;

	prepare_flood(img, &flood);
	if (!flood.visited)
		return (0);
	flood.visited[img->player_y][img->player_x] = 1;
	recurse_up(&flood, img->player_x, img->player_y);
	recurse_down(&flood, img->player_x, img->player_y);
	recurse_left(&flood, img->player_x, img->player_y);
	recurse_right(&flood, img->player_x, img->player_y);
	result = (flood.items_found == flood.items_total && flood.exit_found);
	free_visited(flood.visited, flood.map_h);
	img->total_items = flood.items_total;
	return (result);
}

void	prepare_flood(t_img *img, t_flood *flood)
{
	int	x;
	int	y;

	flood->items_total = 0;
	flood->items_found = 0;
	flood->exit_found = 0;
	y = 0;
	while (y < img->map_height)
	{
		x = 0;
		while (x < img->map_width)
		{
			if (img->map[y][x] == 'C')
				flood->items_total++;
			x++;
		}
		y++;
	}
	flood->visited = create_visited(img->map_width, img->map_height);
	flood->map = img->map;
	flood->map_w = img->map_width;
	flood->map_h = img->map_height;
}

void	recurse_up(t_flood *f, int x, int y)
{
	int	new_y;

	new_y = y - 1;
	if (new_y < 0 || f->visited[new_y][x])
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
