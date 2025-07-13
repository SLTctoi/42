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
            else if (map[y][x] == 'E' || map[y][x] == 'W')
                    mlx_put_image_to_window(img->mlx, img->win, img->img_exit, x * img->img_width, y * img->img_height);
            x++;
        }
        y++;
    }
}

int resize_window(t_img *img)
{
    draw_map(img, img->map);
    return (0);
}

void is_rectangular(t_img *img)
{
    size_t len;
    int i;
    int ok;

    ok = 1;
    len = ft_strlen(img->map[0]);
    i = 1;
    while (img->map[i])
    {
        if (ft_strlen(img->map[i]) != len)
            ok = 0;
        i++;
    }
    if (!ok)
    {
        write(2, "Error\nThe map is incorrect.\n", 28);
        if (img->map)
		    final_free(img->map);
	    if (img->win)
		    mlx_destroy_window(img->mlx, img->win);
        exit(0);
    }
}