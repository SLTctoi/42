/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:16:59 by mchrispe          #+#    #+#             */
/*   Updated: 2025/07/15 12:54:05 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_img
{
	char	**map;
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_item;
	int		img_width;
	int		img_height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		count_move;
	int		map_width;
	int		map_height;
	int		total_items;
}			t_img;

typedef struct s_flood
{
	char	**map;
	int		**visited;
	int		map_w;
	int		map_h;
	int		items_total;
	int		items_found;
	int		exit_found;
}			t_flood;

// free
void		final_free(char **map);
void		exit_victory(t_img *img);
int			close_window(t_img *img);
void		error_map_border(t_img *img);

// img
void		load_img(t_img *img);

// key
int			key_hook(int keycode, t_img *img);
void		move_up(t_img *img);
void		move_down(t_img *img);
void		move_left(t_img *img);
void		move_right(t_img *img);

// main
int			load_and_prepare_map(t_img *img, char *filename);
int			validate_map(t_img *img);

// map
void		draw_map(t_img *img, char **map);
int			resize_window(t_img *img);
void		is_rectangular(t_img *img);
void		map_border(t_img *img);

// parse_entry
int			count_lines_file(char *filename);
void		free_map(char **map, int lines);
char		**alloc_and_open(char *filename, int *lines, int *fd);
int			read_map_lines(int fd, char **map, int lines);
char		**parse_map(char *filename);

// pos
void		init_player_pos(t_img *img);
void		init_exit_pos(t_img *img);

// utils
void		add_and_print_move(t_img *img);
int			ber_extension(char *filename);
int			count_item(t_img *img);
void		draw_tile(t_img *img, char tile, int x, int y);

// valid_map
int			count_exit(t_img *img);
int			count_player(t_img *img);

// valid_path
int			**create_visited(int w, int h);
void		free_visited(int **matrix, int h);
int			check_map_access(t_img *img);
void		prepare_flood(t_img *img, t_flood *flood);
void		recurse_up(t_flood *f, int x, int y);

// valid_path2
void		recurse_down(t_flood *f, int x, int y);
void		recurse_left(t_flood *f, int x, int y);
void		recurse_right(t_flood *f, int x, int y);
int			get_map_width(char **map);
int			get_map_height(char **map);

#endif