#include "cub3D.h"

static void	assign_texture(char *id, char *value, t_map *map)
{
	if (!ft_strncmp(id, "NO", 3))
	{
		if (!map->NO)
			map->NO = ft_strdup(value);
		else
			exit_error(ERROR_DUPLICATE, map);
	}
	else if (!ft_strncmp(id, "SO", 3))
	{
		if (!map->SO)
			map->SO = ft_strdup(value);
		else
			exit_error(ERROR_DUPLICATE, map);
	}
	else if (!ft_strncmp(id, "WE", 3))
	{
		if (!map->WE)
			map->WE = ft_strdup(value);
		else
			exit_error(ERROR_DUPLICATE, map);
	}
}

static void	assign_texture_ea(char *id, char *value, t_map *map)
{
	if (!ft_strncmp(id, "EA", 3))
	{
		if (!map->EA)
			map->EA = ft_strdup(value);
		else
			exit_error(ERROR_DUPLICATE, map);
	}
}

static void	assign_color(char *id, char *value, t_map *map)
{
	if (!ft_strncmp(id, "F", 2) || !ft_strncmp(id, "C", 2))
		assign_color_value(id, value, map);
}

void	assign_value(char *identifier, char *value, t_map *map)
{
	assign_texture(identifier, value, map);
	assign_texture_ea(identifier, value, map);
	assign_color(identifier, value, map);
}
