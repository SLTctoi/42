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
# include "mlx.h"

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
# define ERROR_XPM_EXT "Error: Texture must be a .xpm file for"
# define ERROR_TEXTURE_PATH "Error: Invalid texture path\n"

# define WHITESPACES " \t\v\f\r"
# define BUFFER_SIZE 32
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768
# define TILE_SIZE 20
# define MOVE_SPEED 0.1
# define ROT_SPEED  0.05
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363



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

typedef struct s_player
{
	double pos_x;
	double pos_y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
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

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_screen	screen;
	t_texture	tex_no;
	t_texture	tex_so;
	t_texture	tex_we;
	t_texture	tex_ea;
	t_map		map;
	t_player	player;
}	t_game;

/* error */
void	exit_error(char *msg, t_map *map);
void	error_xpm_ext(char *identifier, t_map *map);
void	error_too_many_args(char *identifier, t_map *map);

/* parsing_map */
int		open_file(char *arg, t_map *map);
void	init_map_struct(t_map *map);
t_map	parse_entry_file(int fd);

/* parsing_line */
int		its_map(char *str);
void	parse_line(char *line, t_map *map, int map_started);
void	check_empty_lines_after(char *str, int map_started, int fd, t_map *map);

/* parsing_assign */
void	assign_value(char *identifier, char *value, t_map *map);

/* parsing_color */
void	assign_color_value(char *identifier, char *value, t_map *map);

/* parsing_extract */
char	*extract_value_with_quotes(char *line, int *pos, t_map *map);
char	*extract_value_no_quotes(char *line, int *pos, t_map *map);
char	*extract_identifier(char *line, int *pos);

/* parsing_realloc */
char	**ft_realloc_map(char **old_map, int old_size, char *line, t_map *map);

/* parsing_utils */
int		count_map_lines(char **map);
void	check_no_extra_args(char *line, int pos, char *identifier, t_map *map);
int		skip_whitespace(char *str);

/* get_next_line */
char	*get_next_line(int fd, t_map *map);

/* free */
void	free_token(char **tok);
void	free_map(t_map *map);
void	gnl_cleanup(void);

/* validation */
void	textures_is_valid(t_map map);
void	validate_map_closed(t_map *map);
void	validate_map_spaces(t_map *map);
void	validate_player_count(t_map *map);
void	validate_all_elements(t_map *map);

/* step 2 / 3: MLX */
void	init_mlx(t_game *game);
int		render_frame(t_game *game);
int		key_hook(int keycode, t_game *game);
int		close_window(t_game *game);

/* textures */
void		load_textures(t_game *game);
t_texture	*select_texture(t_game *game, t_ray *ray);
double		calculate_wall_x(t_game *game, t_ray *ray);
int			get_texture_color(t_texture *tex, int tex_x, int tex_y);

/* raycasting */
void	init_ray_direction(t_ray *ray, t_player *player, int x);
void	init_ray_delta(t_ray *ray);
void	init_ray_step(t_ray *ray, t_player *player);
void	perform_dda(t_ray *ray, t_map *map);
void	calculate_wall_distance(t_ray *ray, t_player *player);
void	render_wall_slice(t_game *game, t_ray *ray, int x);
void	cast_rays(t_game *game);

/* player */
void	init_player(t_map *map, t_player *player);
void	set_dir_plane(char start, t_player *player);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	strafe_left(t_game *game);
void	strafe_right(t_game *game);
void	rotate_player(t_player *player, double angle);
void	draw_line(t_game *game, int x0, int y0, int x1, int y1);

/*render*/
void	draw_pixel(t_game *game, int x, int y, int color);
void	draw_square(t_game *game, int x, int y, int color);
void	draw_map(t_game *game);
void	draw_player(t_game *game);
int		map_width(t_game *game);
int		map_height(t_game *game);

/*raycasting*/

void	cast_rays(t_game *game);




#endif

