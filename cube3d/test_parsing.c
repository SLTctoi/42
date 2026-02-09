/* Simple test program for parsing */
#include "cub3D.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_map map;
	int fd;
	
	if (argc != 2)
	{
		printf("Usage: %s <file.cub>\n", argv[0]);
		return (1);
	}
	
	ft_memset(&map, 0, sizeof(t_map));
	
	fd = open_file(argv[1], &map);
	if (fd == -1)
		return (1);
	
	map = parse_entry_file(fd);
	
	if (map.no && map.so && map.we && map.ea && map.f_set && map.c_set)
	{
		printf("✓ Parsing réussi!\n");
		printf("NO: %s\n", map.no);
		printf("SO: %s\n", map.so);
		printf("WE: %s\n", map.we);
		printf("EA: %s\n", map.ea);
		printf("F: %d,%d,%d\n", map.f[0], map.f[1], map.f[2]);
		printf("C: %d,%d,%d\n", map.c[0], map.c[1], map.c[2]);
	}
	
	close(fd);
	free_map(&map);
	return (0);
}
