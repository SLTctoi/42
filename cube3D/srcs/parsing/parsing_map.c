#include "cub3D.h"

// return fd if valid
// or error + exit 
int open_file(char *arg)
{
    size_t arg_len;
    int fd;

    arg_len = ft_strlen(arg);
    if (arg_len < 4 || ft_strncmp(arg + arg_len - 4, ".cub", 4) != 0)
        exit_error(ERROR_CUB);
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
    map->c = NULL;
    map->map = NULL;
}
// return 1 if map or return 0 if its not
static int its_map(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] != 'S' 
            && str[i] != 'E' && str[i] != 'W' && str[i] != ' ')
            return (0);  // Caractère invalide
        i++;
    }
    return (1);  // Toute la ligne est valide
}

t_map parse_entry_file(int fd)
{
    int br;
    int i;
    char *str;
    t_map map;
    
    init_map_struct(&map);
    str = get_next_line(fd);
    while (str)
    {
        i = 0;
        while (ft_iswhitespace(str[i]))
            i++;
        if (str[i] == '\0')
        {
            free(str);
            str = get_next_line(fd);
            continue;
        }
        // TODO: Add parsing logic here (textures, colors, map)
        free(str);
        str = get_next_line(fd);
    }
    return (map);
}

