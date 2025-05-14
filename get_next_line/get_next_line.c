#include "get_next_line.h"

char	*read_and_store(int fd, char *buffer)
{
	char	*temp;
	char	*joined;
	ssize_t	bytes_read;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		joined = ft_strjoin(buffer, temp);
		free(buffer);
		buffer = joined;
	}
	free(temp);
	return (buffer);
}

char	*extract_line(char **buffer)
{
	char	*newline_pos;
	char	*line;
	char	*temp;

	if (!*buffer || !**buffer)
		return (NULL);
	newline_pos = ft_strchr(*buffer, '\n');
	if (newline_pos)
	{
		line = ft_substr(*buffer, 0, newline_pos - *buffer + 1);
		temp = ft_strdup(newline_pos + 1);
	}
	else
	{
		line = ft_strdup(*buffer);
		temp = NULL;
	}
	free(*buffer);
	*buffer = temp;
	return (line);
}

char	*update_buffer(int fd, char *buffer)
{
	if (!buffer)
		buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	buffer = read_and_store(fd, buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = update_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(&buffer);
	return (line);
}
