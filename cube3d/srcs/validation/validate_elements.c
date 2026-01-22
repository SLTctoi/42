#include "cub3D.h"

void	validate_all_elements(t_map *map)
{
	if (!map->NO)
		exit_error("Error: Missing NO texture\n", map);
	if (!map->SO)
		exit_error("Error: Missing SO texture\n", map);
	if (!map->WE)
		exit_error("Error: Missing WE texture\n", map);
	if (!map->EA)
		exit_error("Error: Missing EA texture\n", map);
	if (!map->F_set)
		exit_error("Error: Missing F color\n", map);
	if (!map->C_set)
		exit_error("Error: Missing C color\n", map);
	if (!map->map)
		exit_error("Error: Missing map\n", map);
}
