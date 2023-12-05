/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_map_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <aapostol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:24:12 by aapostol          #+#    #+#             */
/*   Updated: 2023/11/26 18:24:13 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_walls(char **map, int x, int y, int ymax)
{
	int	xmax;

	xmax = ft_strlen(map[y]);
	if (map[y][x] == '0' && (y != 0 && y != ymax - 1) && \
		(is_abyss(map[y - 1][x]) || is_abyss(map[y + 1][x]) || \
		is_abyss(map[y][x + 1]) || is_abyss(map[y][x - 1])))
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
	if (space_count > 0 && char_count == 0)
		return (1);
	return (0);
}

int	map_check_quali(t_data *data, char **map)
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
		map_size(data, x, y);
	}
	return (0);
}

void	map_size(t_data *data, int x, int y)
{
	if (x > data->width)
		data->width = x;
	if (y > data->height)
		data->height = y;
}