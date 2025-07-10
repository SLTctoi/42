#include "so_long.h"

void    draw_map(t_img *img, char **map)
{
    int x;
    int y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            mlx_put_image_to_window(img->mlx, img->win, img->img_floor, x * img->img_width, y * img->img_height);
            if (map[y][x] == '1')
                mlx_put_image_to_window(img->mlx, img->win, img->img_wall, x * img->img_width, y * img->img_height);
            else if (map[y][x] == '0')
                mlx_put_image_to_window(img->mlx, img->win, img->img_floor, x * img->img_width, y * img->img_height);
            else if (map[y][x] == 'P')
                mlx_put_image_to_window(img->mlx, img->win, img->img_player, x * img->img_width, y * img->img_height);
            else if (map[y][x] == 'C')
                mlx_put_image_to_window(img->mlx, img->win, img->img_item, x * img->img_width, y * img->img_height);
            else if (map[y][x] == 'E')
                    mlx_put_image_to_window(img->mlx, img->win, img->img_exit, x * img->img_width, y * img->img_height);
            x++;
        }
        y++;
    }
}
