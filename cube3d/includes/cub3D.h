/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:01:08 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/09 13:31:12 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* errors */
# define ERROR_USAGE "Usage: ./cub3D map.cub\n"
# define ERROR_MALLOC "Error: Memory allocation failed\n"
# define ERROR_CUB_EXT "Error: The file must have the .cub extension\n"
# define ERROR_GNL "Error: Invalid parameters for get_next_line\n"
# define ERROR_MAP_NOT_LAST "Error: Map must be after all textures and colors\n"
# define ERROR_DUPLICATE "Error: Duplicate texture or color\n"
# define ERROR_EMPTY_LINE_MAP "Error: Empty line in map\n"
# define ERROR_LINE_FORMAT "Error: Invalid line format\n"
# define ERROR_TOO_MANY_ARGS "Error: Too many arguments for"
# define ERROR_INVALID_MAP_CHAR "Error: Inv. char. in map (0,1,N,S,E,W,space)\n"
# define ERROR_RGB_FORMAT "Error: RGB format must be R,G,B (integers only)\n"
# define ERROR_RGB_RANGE "Error: RGB values must be between 0 and 255\n"
# define ERROR_RGB_COUNT "Error: RGB must have exactly 3 values (R,G,B)\n"
# define ERROR_RGB_NOT_NUMBER "Error: RGB value must be a number\n"
# define ERROR_RGB_TOO_LARGE "Error: RGB value too large (max 255)\n"
# define ERROR_RGB_OUT_OF_RANGE "Error: RGB value out of range (0-255)\n"
# define ERROR_XPM_EXT "Error: Texture must be a .xpm file for"
# define ERROR_TEXTURE_PATH "Error: Invalid texture path\n"
# define ERROR_MISSING_ELEMENTS \
"Error: Missing required elements (NO, SO, WE, EA, F, C) before map starts\n"
# define ERROR_MAP_NOT_CLOSED_SPACE "Error: Map not closed (space adjacent)\n"
# define ERROR_MAP_NOT_CLOSED_TOP_BOT "Error: Map not closed (top/bottom)\n"
# define ERROR_MAP_NOT_CLOSED_LEFT "Error: Map not closed (left side)\n"
# define ERROR_MAP_NOT_CLOSED_RIGHT "Error: Map not closed (right side)\n"
# define ERROR_EMPTY_MAP "Error: Empty map\n"
# define ERROR_NO_PLAYER "Error: No player start position (N/S/E/W)\n"
# define ERROR_MULTIPLE_PLAYERS "Error: Multiple player start positions\n"
# define ERROR_MISSING_NO "Error: Missing NO texture\n"
# define ERROR_MISSING_SO "Error: Missing SO texture\n"
# define ERROR_MISSING_WE "Error: Missing WE texture\n"
# define ERROR_MISSING_EA "Error: Missing EA texture\n"
# define ERROR_MISSING_F "Error: Missing F color\n"
# define ERROR_MISSING_C "Error: Missing C color\n"
# define ERROR_MISSING_MAP "Error: Missing map\n"
# define ERROR_NO_PLAYER_START "Error: No player start found\n"
# define ERROR_MISSING_TEXTURE "Error: Missing texture path\n"
# define ERROR_LOAD_TEXTURE "Error: Failed to load texture: "
# define ERROR_TEXTURE_DATA "Error: Failed to get texture data\n"
# define ERROR_MLX_INIT "Error: MLX init failed\n"
# define ERROR_WINDOW_CREATION "Error: Window creation failed\n"
# define ERROR_IMAGE_CREATION "Error: Image creation failed\n"

/* config */
# define WHITESPACES " \t\v\f\r"
# define BUFFER_SIZE 32
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768
# define TILE_SIZE 20
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

/* keys */
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	int		f_set;
	int		c_set;
	char	**map;
	int		fd;
	char	*gnl_buffer;
	char	*tmp_identifier;
	char	*tmp_value;
	char	*current_line;
	char	**tmp_split;
}	t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
}	t_ray;

typedef struct s_screen
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_screen;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;

typedef struct s_wall_pixel
{
	t_texture	*tex;
	int			tex_x;
	double		tex_pos;
	double		step;
	int			x;
	int			y;
}	t_wall_pixel;

typedef struct s_parse_ctx
{
	t_map	*map;
	char	*line;
	char	*identifier;
	char	*value;
	int		pos;
}	t_parse_ctx;

typedef struct s_gnl_ctx
{
	int		fd;
	char	*buffer;
}	t_gnl_ctx;

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_keys		keys;
	t_screen	screen;
	t_texture	tex_no;
	t_texture	tex_so;
	t_texture	tex_we;
	t_texture	tex_ea;
	t_map		map;
	t_player	player;
}	t_game;

t_texture	*select_texture(t_game *game, t_ray *ray);

/* error */
void		exit_error(char *msg, t_map *map);
void		error_xpm_ext(char *identifier, t_map *map);
void		error_too_many_args(char *identifier, t_map *map);

/* parsing_map */
int			open_file(char *arg, t_map *map);
void		init_map_struct(t_map *map);
t_map		parse_entry_file(int fd);

/* parsing_line */
int			its_map(char *str);
int			parse_line(char *line, t_map *map, int map_started);
void		check_empty_lines_after(char *str, int map_started,
				t_map *map, t_gnl_ctx *ctx);

/* parsing_assign */
int			assign_value(char *identifier, char *value, t_map *map);
int			parse_config_line(char *line, t_map *map);

/* parsing_color */
int			assign_color_value(char *identifier, char *value, t_map *map);
char		*extract_color_value(char *line, int *pos, t_map *map);
int			is_valid_number(char *str);

/* parsing_extract */
char		*extract_value_with_quotes(char *line, int *pos, t_map *map);
char		*extract_value_no_quotes(char *line, int *pos, t_map *map);
char		*extract_identifier(char *line, int *pos);

/* parsing_validate_keys */
int			is_valid_key(char *key);
int			is_duplicate_key(char *key, t_map *map);
void		validate_key(char *key, t_map *map);

/* parsing_realloc */
char		**ft_realloc_map(char **old_map, int old_size,
				char *line, t_map *map);

/* parsing_utils */
int			count_map_lines(char **map);
int			check_no_extra_args(char *line, int *pos, char *identifier);
int			skip_whitespace(char *str);
int			has_isolated_ones_at_start(char *str);
void		check_map_chars(char *str, t_map *map);
int			process_file_line(char *str, int *map_started,
				t_map *map, t_gnl_ctx *ctx);
int			parse_non_map_line(char *line, t_map *map, int map_started);
int			parse_map_line(char *line, t_map *map);
int			parse_non_map_line(char *line, t_map *map, int map_started);
int			its_map(char *str);

/* get_next_line */
char		*get_next_line(int fd, char **buf, t_map *map);

/* free */
void		free_token(char **tok);
void		free_map(t_map *map);
void		gnl_cleanup(void);

/* validation */
void		textures_is_valid(t_map *map);
void		validate_map_closed(t_map *map);
void		validate_map_spaces(t_map *map);
void		validate_player_count(t_map *map);
void		validate_all_elements(t_map *map);

/* mlx */
void		init_mlx(t_game *game);
int			render_frame(t_game *game);
int			key_hook(int keycode, t_game *game);
int			close_window(t_game *game);

/* textures */
int			get_texture_color(t_texture *tex, int tex_x, int tex_y);
void		load_textures(t_game *game);
double		calculate_wall_x(t_game *game, t_ray *ray);

/* raycasting */
void		init_ray_direction(t_ray *ray, t_player *player, int x);
void		init_ray_delta(t_ray *ray);
void		init_ray_step(t_ray *ray, t_player *player);
void		perform_dda(t_ray *ray, t_map *map);
void		calculate_wall_distance(t_ray *ray, t_player *player);
void		render_wall_slice(t_game *game, t_ray *ray, int x);
void		cast_rays(t_game *game);

/* player */
void		init_player(t_map *map, t_player *player);
void		set_dir_plane(char start, t_player *player);
void		move_forward(t_game *game);
void		move_backward(t_game *game);
void		strafe_left(t_game *game);
void		strafe_right(t_game *game);
void		rotate_player(t_player *player, double angle);
void		dir_north(t_player *p);
void		dir_south(t_player *p);
void		dir_east(t_player *p);
void		dir_west(t_player *p);
int			key_release(int keycode, t_game *game);
int			key_press(int keycode, t_game *game);

/* render */
void		draw_pixel(t_game *game, int x, int y, int color);
void		draw_square(t_game *game, int x, int y, int color);
void		draw_map(t_game *game);
void		draw_player(t_game *game);
int			map_width(t_game *game);
int			map_height(t_game *game);

#endif
