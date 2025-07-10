#include "so_long.h"

void init_player_pos(t_img *img)
{
    int y;
    int x;

    y = 0;
    while (img->map[y])
    {
        x = 0;
        while (img->map[y][x])
        {
            if (img->map[y][x])
            {
                img->player_x = x;
                img->player_y = y;
                return ;
            }
            x++;
        }
        y++;
    }
}