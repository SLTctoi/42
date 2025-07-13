#include "so_long.h"

int count_item(t_img *img)
{
    int y;
    int x;
    int count;

    y = 0;
    count = 0;
    while (img->map[y])
    {
        x = 0;
        while (img->map[y][x])
        {
            if (img->map[y][x] == 'C')
                count++;
            x++;
        }
        y++;
    }
    return (count);
}