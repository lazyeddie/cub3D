/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <aapostol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:28:29 by aapostol          #+#    #+#             */
/*   Updated: 2023/12/07 14:58:41 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_game *game, t_player *player, int keysym)
{
	if (keysym == XK_w)
		move_sagittal(game, player, true);
	else if (keysym == XK_s)
		move_sagittal(game, player, false);
	else if (keysym == XK_a)
		move_lateral(game, player, false);
	else if (keysym == XK_d)
		move_lateral(game, player, true);
	else if (keysym == XK_Left)
		rotate_left(player);
	else if (keysym == XK_Right)
		rotate_right(player);
}

/*
1111111111111
1000000000001
100001S000001
1000001000001
1000000000001
1111111111111

player (x0 | y0) => ( 6 | 2 )
next (x1 | y1) => ( 5 | 3 )

--> if difference between x0 and x1 as well as y0 and y1 is not 0,
next is diagonally placed from the players current position

if next is diagonally placed, 
you need to check the fields that are left and right between 
player'scurrent position and next
(x0 | y1) and (x1 | y0) => ( 6 | 3 ) and ( 5 | 2 )
*/

int	is_diagonal_wall(t_game *game, t_player *player)
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	char	**map;

	x0 = (int)player->pos_x;
	y0 = (int)player->pos_y;
	x1 = player->next_x;
	y1 = player->next_y;
	map = game->data->map;
	if (x0 - x1 != 0 && y0 - y1 != 0)
		return (map[y0][x1] == '1' || map[y1][x0] == '1');
	return (0);
}

void	move_sagittal(t_game *game, t_player *player, bool front)
{
	float	move_x;
	float	move_y;

	move_x = STEP * player->dir_x;
	move_y = STEP * player->dir_y;
	if (!front)
	{
		move_x *= -1;
		move_y *= -1;
	}
	player->next_x = (int)(player->pos_x + move_x);
	player->next_y = (int)(player->pos_y + move_y);
	if (game->data->map[player->next_y][player->next_x] != '1' && \
		!is_diagonal_wall(game, player))
	{
		player->pos_x += move_x;
		player->pos_y += move_y;
	}
}

void	move_lateral(t_game *game, t_player *player, bool right)
{
	float	move_x;
	float	move_y;

	move_x = STEP * player->plane_x;
	move_y = STEP * player->plane_y;
	if (!right)
	{
		move_x *= -1;
		move_y *= -1;
	}
	player->next_x = (int)(player->pos_x + move_x);
	player->next_y = (int)(player->pos_y + move_y);
	if (game->data->map[player->next_y][player->next_x] && \
		game->data->map[player->next_y][player->next_x] != '1' && \
		!is_diagonal_wall(game, player))
	{
		player->pos_x += move_x;
		player->pos_y += move_y;
	}
}
