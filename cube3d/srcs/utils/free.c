#include "cub3D.h"

void    free_token(char **tok)
{
    int i;

    if (!tok)
        return ;
    i = 0;
    while (tok[i])
    {
        free(tok[i]);
        i++;
    }
    free(tok);
}

void	free_map(t_map *map)
{
	int	i;

	if (map->NO)
		free(map->NO);
	if (map->SO)
		free(map->SO);
	if (map->WE)
		free(map->WE);
	if (map->EA)
		free(map->EA);

	if (map->map)
	{
		i = 0;
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}


