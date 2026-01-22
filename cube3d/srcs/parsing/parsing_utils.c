#include "cub3D.h"

int	count_map_lines(char **map)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	check_no_extra_args(char *line, int pos, char *identifier, t_map *map)
{
	while (ft_iswhitespace(line[pos]))
		pos++;
	if (line[pos] && line[pos] != '\n')
		error_too_many_args(identifier, map);
}

int	skip_whitespace(char *str)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	return (i);
}