/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:32:00 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:32:02 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*ft_join_and_free(char *buf, char *temp)
{
	char	*new_buf;

	new_buf = ft_strjoin(buf, temp);
	free(buf);
	return (new_buf);
}

static char	*ft_read_to_buffer(int fd, char *buf, t_map *map)
{
	char	temp[BUFFER_SIZE + 1];
	int		bytes;

	if (!buf)
		buf = ft_calloc(1, 1);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			exit_error(NULL, map);
		}
		temp[bytes] = '\0';
		buf = ft_join_and_free(buf, temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (buf);
}

static char	*ft_extract_line(char *buf, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		exit_error(NULL, map);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*ft_remove_first_line(char *buf, t_map *map)
{
	char	*new_buf;
	int		i;
	int		j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	new_buf = ft_calloc(ft_strlen(buf) - i, sizeof(char));
	if (!new_buf)
		exit_error(NULL, map);
	i++;
	j = 0;
	while (buf[i])
		new_buf[j++] = buf[i++];
	new_buf[j] = '\0';
	free(buf);
	return (new_buf);
}

char	*get_next_line(int fd, char **buf, t_map *map)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		exit_error(ERROR_GNL, map);
	*buf = ft_read_to_buffer(fd, *buf, map);
	if (!*buf)
		return (NULL);
	line = ft_extract_line(*buf, map);
	*buf = ft_remove_first_line(*buf, map);
	return (line);
}
