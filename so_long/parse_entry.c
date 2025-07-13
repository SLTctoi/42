#include "so_long.h"

int count_lines_file(char *filename)
{
    int fd;
    char *line;
    int count;

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

void free_map(char **map, int lines)
{
    while (--lines > 0)
        free(map[lines]);
    free(map);
}

char **parse_map(char *filename)
{
    int fd;
    int lines;
    char **map;
    int i;
    int len;

    lines = count_lines_file(filename);
    if (lines <= 0)
        return (NULL);
    map = malloc(sizeof(char *) * (lines + 1));
    if (!map)
        return (NULL);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        free(map);
        return (NULL);
    }
    i = 0;
    while (i < lines)
    {
        map[i] = get_next_line(fd);
        if (!map[i])
        {
            free_map(map, i);
            close(fd);
            return (NULL);
        }
        len = ft_strlen(map[i]);
        if (len > 0 && map[i][len - 1] == '\n')
            map[i][len - 1] = '\0';
        i++;
    }
    map[i] = NULL;
    close(fd);
    return (map);
}
// return 0 si prob
int ber_extension(char *filename)
{
    int i;

    if (!filename)
        return (0);
    i = 0;
    while (filename[i])
        i++;
    if (i < 4)
        return (0);
    if (filename[i - 4] == '.' && filename[i - 3] == 'b' &&
        filename[i - 2] == 'e' && filename[i - 1] == 'r')
        return (1);
    return (0);
}