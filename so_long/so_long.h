#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>

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
}   t_img;

void    draw_map(t_img *img, char **map);
void load_img(t_img *img);

int key_hook(int keycode, t_img *img);
void move_up(t_img *img);
void move_down(t_img *img);
void move_left(t_img *img);
void move_right(t_img *img);

void init_player_pos(t_img *img);

#endif