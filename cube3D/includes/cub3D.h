#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

# define ERROR_CUB_EXT "Error: The file must have the .cub extension\n"
# define ERROR_GNL "Error: Invalid parameters for get_next_line\n"
# define ERROR_MAP_NOT_LAST "Error: Map must be after all textures and colors\n"
# define ERROR_DUPLICATE "Error: Duplicate texture or color\n"
# define ERROR_EMPTY_LINE_MAP "Error: Empty line in map\n"
# define ERROR_LINE_FORMAT "Error: Invalid line format\n"

# define WHITESPACES " \t\v\f\r"
# define BUFFER_SIZE 32

typedef struct s_map
{
    char *NO;
    char *SO;
    char *WE;
    char *EA;
    char *F;
    char *C;
    char **map;
}   t_map;

// error.c
void exit_error(char *msg);

// parsing_map.c
int open_file(char *arg);

// parsing_utils.c
int count_map_lines(char **map);

// get_next_line.c
char	*get_next_line(int fd);

// free.c
void    free_token(char **tok);
t_map   parse_entry_file(int fd);
char    **ft_realloc_map(char **old_map, int old_size, char *line);


#endif