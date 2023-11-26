/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <aapostol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:28:29 by aapostol          #+#    #+#             */
/*   Updated: 2023/11/26 18:33:54 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_game *game, t_player *player, int keysym)
{
	if (keysym == XK_w)
		move_forward(game, player);
	else if (keysym == XK_s)
		move_backward(game, player);
	else if (keysym == XK_a)
		move_left(game, player);
	else if (keysym == XK_d)
		move_right(game, player);
	else if (keysym == XK_Left)
		rotate_left(player);
	else if (keysym == XK_Right)
		rotate_right(player);
}

void	move_forward(t_game *game, t_player *player)
{
	float	move_x;
	float	move_y;

	move_x = STEP * player->dir_x;
	move_y = STEP * player->dir_y;
	player->next_x = (int)(player->pos_x + move_x);
	player->next_y = (int)(player->pos_y + move_y);
	if (game->data->map[player->next_y][player->next_x] != '1')
	{
		player->pos_x += move_x;
		player->pos_y += move_y;
	}
}

void	move_backward(t_game *game, t_player *player)
{
	float	move_x;
	float	move_y;

	move_x = -STEP * player->dir_x;
	move_y = -STEP * player->dir_y;
	player->next_x = (int)(player->pos_x + move_x);
	player->next_y = (int)(player->pos_y + move_y);
	if (game->data->map[player->next_y][player->next_x] != '1')
	{
		player->pos_x += move_x;
		player->pos_y += move_y;
	}
}

void	move_left(t_game *game, t_player *player)
{
	float	move_x;
	float	move_y;

	move_x = -STEP * player->plane_x;
	move_y = -STEP * player->plane_y;
	player->next_x = (int)(player->pos_x + move_x);
	player->next_y = (int)(player->pos_y + move_y);
	if (game->data->map[player->next_y][player->next_x] && \
		game->data->map[player->next_y][player->next_x] != '1')
	{
		player->pos_x += move_x;
		player->pos_y += move_y;
	}
}

void	move_right(t_game *game, t_player *player)
{
	float	move_x;
	float	move_y;

	move_x = STEP * player->plane_x;
	move_y = STEP * player->plane_y;
	player->next_x = (int)(player->pos_x + move_x);
	player->next_y = (int)(player->pos_y + move_y);
	if (game->data->map[player->next_y][player->next_x] && \
		game->data->map[player->next_y][player->next_x] != '1')
	{
		player->pos_x += move_x;
		player->pos_y += move_y;
	}
}
