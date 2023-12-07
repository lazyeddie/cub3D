/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_map_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:24:12 by aapostol          #+#    #+#             */
/*   Updated: 2023/12/07 15:31:57 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	valid_field(int c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	check_walls(char **map, int x, int y, int ymax)
{
	int		xmax;
	int		xmax_prev;
	int		xmax_next;

	xmax = ft_strlen(map[y]);
	xmax_next = 0;
	xmax_prev = 0;
	if (valid_field(map[y][x]) && (y != 0 && y != ymax - 1))
	{
		xmax_prev = ft_strlen(map[y - 1]);
		xmax_next = ft_strlen(map[y + 1]);
		if (x >= xmax_prev || x >= xmax_next || is_abyss(map, x, y))
			return (1);
	}
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

	i = 0;
	while (map[i])
	{
		if (map[i] != 32)
			return (0);
		i++;
	}
	if (i == 0 || map[i] == 0)
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
	if (!ymax)
		return (INVALID_MAP_ERR0);
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
