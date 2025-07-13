#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"
# include <stdlib.h>
#include <fcntl.h>

typedef struct s_img
{
    char **map;
    void *mlx;
    void *win;
    void *img_wall;
    void *img_floor;
    void *img_player;
    void *img_exit;
    void *img_item;
    int   img_width;
    int   img_height;
    int   player_x;
    int   player_y;
    int   exit_x;
    int   exit_y;
    int   count_move;
    int map_width;
    int map_height;
}   t_img;

typedef struct s_flood {
    char    **map;
    int     **visited;
    int     map_w;
    int     map_h;
    int     items_total;
    int     items_found;
    int     exit_found;
}   t_flood;

void    draw_map(t_img *img, char **map);
void load_img(t_img *img);

int key_hook(int keycode, t_img *img);
void move_up(t_img *img);
void move_down(t_img *img);
void move_left(t_img *img);
void move_right(t_img *img);

void init_player_pos(t_img *img);

void set_img_map_object(t_img *m, char *map_file);


void final_free(char **map);


int count_lines_file(char *filename);
void free_map(char **map, int lines);
char **parse_map(char *filename);
int ber_extension(char *filename);

char *get_next_line(int fd);
int count_item(t_img *img);
void	exit_victory(t_img *img);
void init_exit_pos(t_img *img);
void add_and_print_move(t_img *img);

int resize_window(t_img *img);
int close_window(t_img *img);
void is_rectangular(t_img *img);

int get_map_width(char **map);
int get_map_height(char **map);
int check_map_access(t_img *img);

#endif