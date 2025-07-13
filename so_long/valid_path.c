#include "so_long.h"

static void recurse_up(t_flood *flood, int x, int y);
static void recurse_down(t_flood *flood, int x, int y);
static void recurse_left(t_flood *flood, int x, int y);
static void recurse_right(t_flood *flood, int x, int y);

static int **create_visited(int w, int h) {
    int **matrix;
    int i;
    int j;

    matrix = malloc(sizeof(int *) * h);
    if (!matrix) 
		return NULL;
    i = 0;
    while (i < h) {
        matrix[i] = malloc(sizeof(int) * w);
        if (!matrix[i]) 
		{
            while (--i >= 0) 
				free(matrix[i]);
            free(matrix);
            return NULL;
        }
        j = 0;
        while (j < w)
			matrix[i][j++] = 0;
        i++;
    }
    return (matrix);
}

static void free_visited(int **matrix, int h) {
    int i;

    i = 0;
    while (i < h) free(matrix[i++]);
    free(matrix);
}

int check_map_access(t_img *img) {
    t_flood flood;
    int result;

    flood.items_total = 0;
    flood.items_found = 0;
    flood.exit_found = 0;
    for (int y = 0; y < img->map_height; y++)
        for (int x = 0; x < img->map_width; x++)
            if (img->map[y][x] == 'C') flood.items_total++;
    flood.visited = create_visited(img->map_width, img->map_height);
    if (!flood.visited) return 0;
    flood.map = img->map;
    flood.map_w = img->map_width;
    flood.map_h = img->map_height;
    flood.visited[img->player_y][img->player_x] = 1;
    recurse_up(&flood, img->player_x, img->player_y);
    recurse_down(&flood, img->player_x, img->player_y);
    recurse_left(&flood, img->player_x, img->player_y);
    recurse_right(&flood, img->player_x, img->player_y);
    result = (flood.items_found == flood.items_total && flood.exit_found);
    free_visited(flood.visited, flood.map_h);
    return result;
}

static void recurse_up(t_flood *f, int x, int y) {
    int new_y;
    new_y = y - 1;
    if (new_y < 0 || f->visited[new_y][x]) return;
    if (f->map[new_y][x] == '1') return;
    f->visited[new_y][x] = 1;
    if (f->map[new_y][x] == 'C') f->items_found++;
    if (f->map[new_y][x] == 'E') f->exit_found = 1;
    recurse_up(f, x, new_y);
    recurse_down(f, x, new_y);
    recurse_left(f, x, new_y);
    recurse_right(f, x, new_y);
}

static void recurse_down(t_flood *f, int x, int y) {
    int new_y;
    new_y = y + 1;
    if (new_y >= f->map_h || f->visited[new_y][x]) return;
    if (f->map[new_y][x] == '1') return;
    f->visited[new_y][x] = 1;
    if (f->map[new_y][x] == 'C') f->items_found++;
    if (f->map[new_y][x] == 'E') f->exit_found = 1;
    recurse_up(f, x, new_y);
    recurse_down(f, x, new_y);
    recurse_left(f, x, new_y);
    recurse_right(f, x, new_y);
}

static void recurse_left(t_flood *f, int x, int y) {
    int new_x;
    new_x = x - 1;
    if (new_x < 0 || f->visited[y][new_x]) return;
    if (f->map[y][new_x] == '1') return;
    f->visited[y][new_x] = 1;
    if (f->map[y][new_x] == 'C') f->items_found++;
    if (f->map[y][new_x] == 'E') f->exit_found = 1;
    recurse_up(f, new_x, y);
    recurse_down(f, new_x, y);
    recurse_left(f, new_x, y);
    recurse_right(f, new_x, y);
}

static void recurse_right(t_flood *f, int x, int y) {
    int new_x;
    new_x = x + 1;
    if (new_x >= f->map_w || f->visited[y][new_x]) return;
    if (f->map[y][new_x] == '1') return;
    f->visited[y][new_x] = 1;
    if (f->map[y][new_x] == 'C') f->items_found++;
    if (f->map[y][new_x] == 'E') f->exit_found = 1;
    recurse_up(f, new_x, y);
    recurse_down(f, new_x, y);
    recurse_left(f, new_x, y);
    recurse_right(f, new_x, y);
}

int get_map_width(char **map)
{
    int x;

    x = 0;
    if (!map || !map[0])
        return (0);
    while (map[0][x] != '\0')
        x++;
    return (x);
}

int get_map_height(char **map)
{
    int y;

    y = 0;
    if (!map)
        return (0);
    while (map[y] != NULL)
        y++;
    return (y);
}