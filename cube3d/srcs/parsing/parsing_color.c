#include "cub3D.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	validate_rgb_value(int value, t_map *map)
{
	if (value < 0 || value > 255)
		exit_error(ERROR_RGB_RANGE, map);
}

static void	parse_rgb(char *value, int rgb[3], t_map *map)
{
	char	**split;
	int		i;

	split = ft_split(value, ",");
	if (!split)
		exit_error(NULL, map);
	i = 0;
	while (split[i])
		i++;
	if (i != 3)
	{
		free_token(split);
		exit_error(ERROR_RGB_COUNT, map);
	}
	i = -1;
	while (++i < 3)
	{
		if (!is_valid_number(split[i]))
		{
			free_token(split);
			exit_error(ERROR_RGB_FORMAT, map);
		}
		validate_rgb_value(rgb[i] = ft_atoi(split[i]), map);
	}
	free_token(split);
}

void	assign_color_value(char *identifier, char *value, t_map *map)
{
	if (!ft_strncmp(identifier, "F", 2))
	{
		if (map->F_set)
			exit_error(ERROR_DUPLICATE, map);
		parse_rgb(value, map->F, map);
		map->F_set = 1;
	}
	else if (!ft_strncmp(identifier, "C", 2))
	{
		if (map->C_set)
			exit_error(ERROR_DUPLICATE, map);
		parse_rgb(value, map->C, map);
		map->C_set = 1;
	}
}
