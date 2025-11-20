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

# define ERROR_CUB "Error: The file must have the .cub extension\n"
# define ERROR_GNL "Error: Invalid parameters for get_next_line\n"
# define BUFFER_SIZE 32

typedef struct s_map
{
    char *NO;
    char *SO;
    char *WE;
    char *EA;
    int *F;
    int *c;
    char **map;
}   t_map;

// error.c
void exit_error(char *msg);

// parsing_map.c
int open_file(char *arg);

// get_next_line.c
char	*get_next_line(int fd);

#endif