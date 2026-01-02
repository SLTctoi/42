#include "cub3D.h"

static void	print_map(char **map)
{
	int	i;

	if (!map)
	{
		printf("  Map: (null)\n");
		return ;
	}
	printf("  Map:\n");
	i = 0;
	while (map[i])
	{
		printf("    [%d]: %s\n", i, map[i]);
		i++;
	}
}

static void	print_textures(t_map *map)
{
	printf("Textures:\n");
	printf("  NO: %s\n", map->NO ? map->NO : "(null)");
	printf("  SO: %s\n", map->SO ? map->SO : "(null)");
	printf("  WE: %s\n", map->WE ? map->WE : "(null)");
	printf("  EA: %s\n", map->EA ? map->EA : "(null)");
}

static void	print_colors(t_map *map)
{
	printf("\nColors:\n");
	if (map->F_set)
		printf("  F (Floor): R=%d, G=%d, B=%d\n",
			map->F[0], map->F[1], map->F[2]);
	else
		printf("  F (Floor): (not set)\n");
	if (map->C_set)
		printf("  C (Ceiling): R=%d, G=%d, B=%d\n",
			map->C[0], map->C[1], map->C[2]);
	else
		printf("  C (Ceiling): (not set)\n");
}

void	print_map_struct(t_map *map)
{
	printf("\n========== MAP STRUCTURE ==========\n\n");
	print_textures(map);
	print_colors(map);
	printf("\n");
	print_map(map->map);
	printf("\n===================================\n\n");
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	if (argc != 2)
	{
		printf("Usage: %s <file.cub>\n", argv[0]);
		return (1);
	}
	fd = open_file(argv[1]);
	map = parse_entry_file(fd);
	close(fd);
	print_map_struct(&map);
	return (0);
}
