#include "cub3D.h"

static int	is_valid_cell(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static void	check_top_bottom(t_map *map, int y)
{
	int	x;

	x = 0;
	while (map->map[y][x])
	{
		if (is_valid_cell(map->map[y][x]))
			exit_error("Error: Map not closed (top/bottom)\n", map);
		x++;
	}
}

static void	check_sides(t_map *map, int y)
{
	int	x;
	int	len;

	x = 0;
	len = ft_strlen(map->map[y]);
	while (map->map[y][x] == ' ')
		x++;
	if (x < len && is_valid_cell(map->map[y][x]))
		exit_error("Error: Map not closed (left side)\n", map);
	x = len - 1;
	while (x >= 0 && map->map[y][x] == ' ')
		x--;
	if (x >= 0 && is_valid_cell(map->map[y][x]))
		exit_error("Error: Map not closed (right side)\n", map);
}

void	validate_map_closed(t_map *map)
{
	int	y;
	int	height;

	height = count_map_lines(map->map);
	if (height == 0)
		exit_error("Error: Empty map\n", map);
	check_top_bottom(map, 0);
	check_top_bottom(map, height - 1);
	y = 1;
	while (y < height - 1)
	{
		check_sides(map, y);
		y++;
	}
}
