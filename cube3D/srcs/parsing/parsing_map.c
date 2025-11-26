#include "cub3D.h"

// return fd if valid
// or error + exit 
int open_file(char *arg)
{
    size_t arg_len;
    int fd;

    arg_len = ft_strlen(arg);
    if (arg_len < 4 || ft_strncmp(arg + arg_len - 4, ".cub", 4) != 0)
        exit_error(ERROR_CUB_EXT);
    fd = open(arg, O_RDONLY);
    if (fd == -1)
        exit_error(NULL);
    return (fd);
}

// fonction qui read le fd 
// la map est obligatoirement le dernier elem du fichier , les autres on s'en fou
static void init_map_struct(t_map *map)
{
    map->NO = NULL;
    map->SO = NULL;
    map->WE = NULL;
    map->EA = NULL;
    map->F = NULL;
    map->C = NULL;
    map->map = NULL;
}
// return 1 if map or return 0 if its not
static int its_map(char *str)
{
    int i;

    i = 0;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] != 'S' 
            && str[i] != 'E' && str[i] != 'W' && str[i] != ' ' && str[i] != '\n')
            return (0);
        i++;
    }
    return (1);
}
static void cond_parse_line_2(char **tok, t_map *map)
{
    if (!ft_strncmp(tok[0], "EA", 2))
    {    
        if (!map->EA)
            map->EA = ft_strdup(tok[1]);
        else
            exit_error(ERROR_DUPLICATE);    
    }
    else if (!ft_strncmp(tok[0], "F", 1))
    {    
        if (!map->F)
            map->F = ft_strdup(tok[1]);
        else
            exit_error(ERROR_DUPLICATE);    
    }
    else if (!ft_strncmp(tok[0], "C", 1))
    {    
        if (!map->C)
            map->C = ft_strdup(tok[1]);
        else
            exit_error(ERROR_DUPLICATE);    
    }
}

static void cond_parse_line_3(char **tok, t_map *map)
{
    if (!ft_strncmp(tok[0], "NO", 2))
    {
        if (!map->NO)
            map->NO = ft_strdup(tok[1]);
        else
            exit_error(ERROR_DUPLICATE);
    }
    else if (!ft_strncmp(tok[0], "SO", 2))
    {
        if (!map->SO)
            map->SO = ft_strdup(tok[1]);
        else
            exit_error(ERROR_DUPLICATE);
    }
}

static void cond_parse_line(char **tok, t_map *map)
{
    if (!ft_strncmp(tok[0], "NO", 2) || !ft_strncmp(tok[0], "SO", 2))
        cond_parse_line_3(tok, map);
    else if (!ft_strncmp(tok[0], "WE", 2))
    {    
        if (!map->WE)
            map->WE = ft_strdup(tok[1]);
        else
            exit_error(ERROR_DUPLICATE);    
    }
    else
        cond_parse_line_2(tok, map);
}

// if its not map -> split
static void parse_line(char *line, t_map *map)
{
    char **tok;

    if (!its_map(line))
    {
        tok = ft_split(line, WHITESPACES);
        if (!tok || !tok[0])
            return ;
        if (!tok[1])
        {
            free_token(tok);
            exit_error(ERROR_LINE_FORMAT);
        }
        tok[1] = ft_strtrim(tok[1], "\n");
        cond_parse_line(tok, map);
        free_token(tok);
    }
    else
    {
        if (!(map->NO && map->SO && map->WE && map->EA && map->F && map->C))
            exit_error(ERROR_MAP_NOT_LAST);
        map->map = ft_realloc_map(map->map, count_map_lines(map->map), line);
    }
}

static void check_empty_lines_after(char *str, int map_started, int fd)
{
    char *next_str;
    int i;

    if (!map_started)
        return ;
    next_str = get_next_line(fd);
    while (next_str)
    {
        i = 0;
        while (ft_iswhitespace(next_str[i]))
            i++;
        if (next_str[i] != '\0')
        {
            free(next_str);
            free(str);
            exit_error(ERROR_EMPTY_LINE_MAP);
        }
        free(next_str);
        next_str = get_next_line(fd);
    }
}

static int skip_whitespace(char *str)
{
    int i;

    i = 0;
    while (ft_iswhitespace(str[i]))
        i++;
    return (i);
}

static void process_file_line(char *str, int *map_started, t_map *map, int fd)
{
    int i;

    i = skip_whitespace(str);
    if (str[i] == '\0')
    {
        check_empty_lines_after(str, *map_started, fd);
        return ;
    }
    if (its_map(str + i))
        *map_started = 1;
    parse_line(str + i, map);
}

t_map parse_entry_file(int fd)
{
    int map_started;
    char *str;
    t_map map;
    
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

char **ft_realloc_map(char **old_map, int old_size, char *line)
{
    char **new_map;
    int i;

    new_map = malloc(sizeof(char *) * (old_size + 2));
    if (!new_map)
        exit_error(NULL);
    i = 0;
    while (i < old_size)
    {
        new_map[i] = old_map[i];
        i++;
    }
    new_map[old_size] = ft_strdup(line);
    if (!new_map[old_size])
        exit_error(NULL);
    if (new_map[old_size][ft_strlen(new_map[old_size]) - 1] == '\n')
        new_map[old_size][ft_strlen(new_map[old_size]) - 1] = '\0';
    new_map[old_size + 1] = NULL;
    free(old_map);
    return (new_map);
}

