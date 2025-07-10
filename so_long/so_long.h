#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>

typedef struct s_img
{
    void *mlx;
    void *win;
    void *img_wall;
    void *img_floor;
    void *img_player;
    void *img_exit;
    void *img_item;
    int   img_width;
    int   img_height;
}   t_img;

void    draw_map(t_img *img, char **map);
void load_img(t_img *img);

#endif