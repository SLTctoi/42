#include "cub3D.h"

int count_map_lines(char **map)
{
    int i;

    if (!map)
        return (0);
    i = 0;
    while (map[i])
        i++;
    return (i);
}