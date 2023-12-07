/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <aapostol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:30:27 by aapostol          #+#    #+#             */
/*   Updated: 2023/12/06 16:51:00 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	spawn_player(t_game *game, t_player *player)
{
	get_player_pos(game, game->data->map, player);
	set_start_dir(player);
}

void	get_player_pos(t_game *game, char **map, t_player *player)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'E' || map[i][j] == 'W')
			{
				player->pos_x = j + 0.5;
				player->pos_y = i + 0.5;
				player->start_dir = map[i][j];
				map[i][j] = '0';
				count++;
			}
			j++;
		}
	}
	if (count != 1)
		free_game(game, ft_strerror(PLAYER_ERR));
}

void	set_start_dir(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	if (player->start_dir == 'N')
	{
		player->dir_y = -1;
		player->plane_x = 0.66;
	}
	else if (player->start_dir == 'S')
	{
		player->dir_y = 1;
		player->plane_x = -0.66;
	}
	else if (player->start_dir == 'E')
	{
		player->dir_x = 1;
		player->plane_y = 0.66;
	}
	else if (player->start_dir == 'W')
	{
		player->dir_x = -1;
		player->plane_y = -0.66;
	}
}
