/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:10:02 by mchrispe          #+#    #+#             */
/*   Updated: 2025/07/14 14:10:03 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines_file(char *filename)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		count++;
	}
	close(fd);
	return (count);
}

void	free_map(char **map, int lines)
{
	while (--lines > 0)
		free(map[lines]);
	free(map);
}

char	**alloc_and_open(char *filename, int *lines, int *fd)
{
	char	**map;

	*lines = count_lines_file(filename);
	if (*lines <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (*lines + 1));
	if (!map)
		return (NULL);
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
	{
		free(map);
		return (NULL);
	}
	return (map);
}
int	read_map_lines(int fd, char **map, int lines)
{
	int	i;
	int	len;

	i = 0;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (0);
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n')
			map[i][len - 1] = '\0';
		i++;
	}
	map[i] = NULL;
	return (1);
}
char	**parse_map(char *filename)
{
	char	**map;
	int		lines;
	int		fd;

	map = alloc_and_open(filename, &lines, &fd);
	if (!map)
		return (NULL);
	if (!read_map_lines(fd, map, lines))
	{
		free_map(map, lines);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (map);
}
