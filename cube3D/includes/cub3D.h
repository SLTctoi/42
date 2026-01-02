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
# define ERROR_TOO_MANY_ARGS "Error: Too many arguments for"
# define ERROR_INVALID_MAP_CHAR "Error: Invalid character in map (allowed: 0,1,N,S,E,W,space)\n"
# define ERROR_RGB_FORMAT "Error: RGB format must be R,G,B (integers only)\n"
# define ERROR_RGB_RANGE "Error: RGB values must be between 0 and 255\n"
# define ERROR_RGB_COUNT "Error: RGB must have exactly 3 values (R,G,B)\n"
# define ERROR_XPM_EXT "Error: Texture must be a .xpm file for"
# define ERROR_TEXTURE_PATH "Error: Invalid texture path\n"

# define WHITESPACES " \t\v\f\r"
# define BUFFER_SIZE 32

typedef struct s_map
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F[3];
	int		C[3];
	int		F_set;
	int		C_set;
	char	**map;
}	t_map;

// error.c
void exit_error(char *msg);

// parsing_map.c
int		open_file(char *arg);
void	init_map_struct(t_map *map);
t_map	parse_entry_file(int fd);

// parsing_line.c
int		its_map(char *str);
void	parse_line(char *line, t_map *map, int map_started);
void	check_empty_lines_after(char *str, int map_started, int fd);

// parsing_assign.c
void	assign_value(char *identifier, char *value, t_map *map);
void	error_too_many_args(char *identifier);

// parsing_color.c
void	assign_color_value(char *identifier, char *value, t_map *map);

// parsing_extract.c
char	*extract_value_with_quotes(char *line, int *pos);
char	*extract_value_no_quotes(char *line, int *pos);
char	*extract_identifier(char *line, int *pos);

// parsing_realloc.c
char	**ft_realloc_map(char **old_map, int old_size, char *line);

// parsing_utils.c
int		count_map_lines(char **map);
void	check_no_extra_args(char *line, int pos, char *identifier);
int		skip_whitespace(char *str);

// get_next_line.c
char	*get_next_line(int fd);

// free.c
void	free_token(char **tok);



#endif