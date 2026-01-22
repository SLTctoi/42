#include "cub3D.h"

int	its_map(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'E' && str[i] != 'W'
			&& str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static void	check_map_chars(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'E' && str[i] != 'W'
			&& str[i] != ' ' && str[i] != '\n')
			exit_error(ERROR_INVALID_MAP_CHAR, map);
		i++;
	}
}

static void	parse_config_line(char *line, t_map *map)
{
	char	*identifier;
	char	*value;
	int		pos;

	identifier = extract_identifier(line, &pos);
	if (!identifier)
		return ;
	if (!ft_strcmp(identifier, "F") || !ft_strcmp(identifier, "C"))
		value = extract_value_no_quotes(line, &pos, map);
	else
		value = extract_value_with_quotes(line, &pos, map);
	if (!value)
	{
		free(identifier);
		exit_error(ERROR_LINE_FORMAT, map);
	}
	check_no_extra_args(line, pos, identifier, map);
	assign_value(identifier, value, map);
	free(identifier);
	free(value);
}

void	parse_line(char *line, t_map *map, int map_started)
{
	if (!its_map(line))
	{
		if (map_started)
			exit_error(ERROR_INVALID_MAP_CHAR, map);
		parse_config_line(line, map);
	}
	else
	{
		if (!(map->NO && map->SO && map->WE && map->EA
				&& map->F_set && map->C_set))
			exit_error(ERROR_MAP_NOT_LAST, map);
		check_map_chars(line, map);
		map->map = ft_realloc_map(map->map,
				count_map_lines(map->map), line, map);
	}
}

void	check_empty_lines_after(char *str, int map_started, int fd, t_map *map)
{
	char	*next_str;
	int		i;

	if (!map_started)
		return ;
	next_str = get_next_line(fd, map);
	while (next_str)
	{
		i = 0;
		while (ft_iswhitespace(next_str[i]))
			i++;
		if (next_str[i] != '\0')
		{
			free(next_str);
			free(str);
			exit_error(ERROR_EMPTY_LINE_MAP, map);
		}
		free(next_str);
		next_str = get_next_line(fd, map);
	}
}
