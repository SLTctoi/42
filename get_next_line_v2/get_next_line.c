#include "get_next_line.h"

char *ft_free_join(char *buffer,char *temp)
{
    char *temp2;

    temp2 = ft_strjoin(buffer, temp);
    free(buffer);
    return (temp);
}

char *ft_first_line(int fd, char *buffer)
{
    char *temp;
    int br;

    if (!buffer)
        text = ft_calloc(1,1);
    temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!temp)
        return (NULL);
    br = 1;
    while (br > 0)
    {
        br = read(fd, temp, BUFFER_SIZE);
        if (br == -1)
        {
            free(buffer);
            free(temp);
            return(NULL);
        }
        temp[br] = 0;
        buffer = ft_free_join(buffer, temp);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(temp);
    return (buffer);
}
char *ft_get_line(char *buffer)
{
    int i;
    char *s;

    i = 0;
    if (!buffer[i])
        return (NULL);
    while(buffer[i] && buffer[i] != '\n')
        i++;
    s = ft_calloc(i + 2, sizeof(char));
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        s[i] = text[i];
        i++;
    }
    if (buffer[i] && buffer[i] != '\n')
        s[i++] = '\n'
    return (s);
}
char *ft_clear_first_line(char *buffer)
{
    int i;
    int j;
    char *s;

    i = 0;
    j = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (!buffer[i])
    {
        free(buffer);
        return (NULL);
    }
    s = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(*buffer));
    if (!s)
        retur (NULL);
    while (buffer[++i])
        s[j++] = buffer[i];
    s[j] = ['\0'];
    free (buffer)
    return (s);
}
char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 && BUFFER_SIZE <= 0)
        return (NULL)
    buffer = ft_first_line(fd, buffer);
    if (!buffer)
        return (NULL);
    line = ft_get_line(buffer);
    buffer = ft_clear_first_line(buffer);
}