#include "parsing.h"

void	update_pec(t_map *map, int x, int y)
{
	if (map->data[y][x] == 'P')
	{
		map->pos.x = x;
		map->pos.y = y;
		map->check.p += 1;
	}
	else if (map->data[y][x] == 'E')
	{
		map->check.exit.x = x;
		map->check.exit.y = y;
		map->check.e += 1;
	}
	else if (map->data[y][x] == 'C')
		map->check.c += 1;
	if (x == map->size.x - 1 && y == map->size.y - 1)
	{
		if (map->check.p != 1)
			err_msg("There must be exactly one player!", map);
		else if (map->check.e != 1)
			err_msg("There must be exactly one exit!", map);
		else if (map->check.c < 1)
			err_msg("There must be at least one collectible!", map);
	}
}

void	check_symbols(t_map *map, int x, int y)
{
	if (map->data[y][x] != 'P' && \
		map->data[y][x] != 'C' && \
		map->data[y][x] != 'E' && \
		map->data[y][x] != '0' && \
		map->data[y][x] != '1')
		err_msg("Wrong symbols!", map);
}

void	check_walls(t_map *map, int x, int y)
{
	if (map->data[0][x] != '1' || \
		map->data[map->size.y - 1][x] != '1' || \
		map->data[y][0] != '1' || \
		map->data[y][map->size.x - 1] != '1')
		err_msg("Missing wall!", map);
}

void	check_rectangle(t_map *map, int y)
{
	if (ft_strlen(map->data[y]) != (size_t)map->size.x)
		err_msg("Map is not rectangular!", map);
}

void	map_check_quali(char **map)
{
	int	x;
	int	y;

	map->size.x = ft_strlen(map->data[0]);
	map->size.y = ft_arrlen(map->data);
	y = 0;
	while (y < map->size.y)
	{
		check_rectangle(map, y);
		x = 0;
		while (x < map->size.x)
		{
			check_walls(map, x, y);
			check_symbols(map, x, y);
			update_pec(map, x, y);
			x++;
		}
		y++;
	}
	map->count = map->check.c;
	flood_fill(map, map->pos.x, map->pos.y);
	revert_map(map);
	if (map->flag != 2)
		err_msg("No valid path!", map);
	ft_printf("Valid map!\n");
}
