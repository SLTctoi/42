/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:21:42 by mchrispe          #+#    #+#             */
/*   Updated: 2025/05/15 10:22:24 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *buffer)
{
    char	*buf;
    ssize_t	r = 1;

    buf = malloc(BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    while (!ft_strchr(buffer, '\n') && r > 0)
    {
        r = read(fd, buf, BUFFER_SIZE);
        if (r < 0)
        {
            free(buf);
            free(buffer);
            return (NULL);
        }
        buf[r] = 0;
        buffer = ft_strjoin(buffer, buf);
        if (!buffer)
            break ;
    }
    free(buf);
    return (buffer);
}

static char	*ft_get_line(char *buffer)
{
    size_t	i = 0;
    char	*line;

    if (!buffer || !buffer[0])
        return (NULL);
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        i++;
    line = ft_substr(buffer, 0, i);
    return (line);
}

static char	*ft_new_buffer(char *buffer)
{
    size_t	i = 0;
    char	*new_buffer;

    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (!buffer[i])
    {
        free(buffer);
        return (NULL);
    }
    new_buffer = ft_substr(buffer, i + 1, ft_strlen(buffer) - i - 1);
    free(buffer);
    return (new_buffer);
}

char	*get_next_line(int fd)
{
    static char	*buffer;
    char		*line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = ft_read(fd, buffer);
    if (!buffer)
        return (NULL);
    line = ft_get_line(buffer);
    buffer = ft_new_buffer(buffer);
    return (line);
}
