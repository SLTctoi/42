#include "cub3D.h"

int	open_file(char *arg)
{
	size_t	arg_len;
	int		fd;

	arg_len = ft_strlen(arg);
	if (arg_len < 4 || ft_strncmp(arg + arg_len - 4, ".cub", 4) != 0)
		exit_error(ERROR_CUB_EXT);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		exit_error(NULL);
	return (fd);
}

void	init_map_struct(t_map *map)
{
	map->NO = NULL;
	map->SO = NULL;
	map->WE = NULL;
	map->EA = NULL;
	map->F_set = 0;
	map->C_set = 0;
	map->map = NULL;
}

static void	process_file_line(char *str, int *map_started, t_map *map, int fd)
{
	int	i;

	i = skip_whitespace(str);
	if (str[i] == '\0')
	{
		check_empty_lines_after(str, *map_started, fd);
		return ;
	}
	if (its_map(str + i))
		*map_started = 1;
	parse_line(str + i, map, *map_started);
}

t_map	parse_entry_file(int fd)
{
	int		map_started;
	char	*str;
	t_map	map;

	init_map_struct(&map);
	map_started = 0;
	str = get_next_line(fd);
	while (str)
	{
		process_file_line(str, &map_started, &map, fd);
		free(str);
		str = get_next_line(fd);
	}
	return (map);
}
