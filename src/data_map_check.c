#include "parsing.h"

int ft_arrlen(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	is_wall(int c)
{
	return (c == '1' || c == ' ');
}

int	is_abyss(int c)
{
	return (!c || c == ' ');
}

int	check_walls(char **map, int x, int y, int ymax)
{
	int	xmax;

	xmax = ft_strlen(map[y]);
	if (map[y][x] == '0' && (is_abyss(map[y - 1][x]) || \
		is_abyss(map[y + 1][x]) || is_abyss(map[y][x + 1]) || \
		is_abyss(map[y][x - 1])))
		return (1);
	if (((y == 0 || y == ymax - 1) && !is_wall(map[y][x])) || \
		((x == 0 || x == xmax - 1) && !is_wall(map[y][x])) || \
		(x != 0 && !is_wall(map[y][x]) && map[y][x - 1] == ' ') || \
		(!is_wall(map[y][x]) && map[y][x + 1] == '\0'))
		return (1);
	return (0);
}

int	lonely_space(char *map)
{
	int	i;
	int	space_count;
	int	char_count;

	i = 0;
	space_count = 0;
	char_count = 0;
	while (map[i])
	{
		if (map[i] == 32 || map[i] == 10)
			space_count++;
		else if (map[i] == 48 || map[i] == 49)
			char_count++;
		i++;
	}
	// printf("count_s: %d count_c: %d\n", space_count, char_count);
	if (space_count > 0 && char_count == 0)
		return (1);
	return (0);
}

int	map_check_quali(char **map)
{
	int	x;
	int	y;
	int	ymax;

	y = 0;
	ymax = ft_arrlen(map);
	while (map[y])
	{
		x = 0;
		if (lonely_space(map[y]))
			return (INVALID_MAP_ERR1);
		while (map[y][x])
		{
			if (check_walls(map, x, y, ymax))
				return (INVALID_MAP_ERR2);
			x++;
		}
		y++;
	}
	return (0);
}
