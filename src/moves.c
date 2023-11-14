#include "cub3d.h"

void	move_player(t_game *game, t_player *player int keysym)
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
		rotate_left(game, player);
	else if (keysym == XK_Right)
		rotate_right(game, player);
}

void	move_forward(t_game *game, t_player *player)
{
	player->next_x = player->pos_x + player->dir_x;
	player->next_y = player->pos_y + player->dir_y;
	if (game->data->map[player->next_y][player->next_x] != '1')
	{
		player->pos_x = player->next_x;
		player->pos_y = player->next_y;
	}
}

void	move_backward(t_game *game, t_player *player)
{
	player->next_x = player->pos_x - player->dir_x;
	player->next_y = player->pos_y - player->dir_y;
	if (game->data->map[player->next_y][player->next_x] != '1')
	{
		player->pos_x = player->next_x;
		player->pos_y = player->next_y;
	}
}

void	move_left(t_game *game, t_player *player)
{
	player->next_x = player->pos_x - player->plane_x;
	player->next_y = player->pos_y - player->plane_y;
	if (game->data->map[player->next_y][player->next_x] != '1')
	{
		player->pos_x = player->next_x;
		player->pos_y = player->next_y;
	}
}

void	move_right(t_game *game, t_player *player)
{
	player->next_x = player->pos_x + player->plane_x;
	player->next_y = player->pos_y + player->plane_y;
	if (game->data->map[player->next_y][player->next_x] != '1')
	{
		player->pos_x = player->next_x;
		player->pos_y = player->next_y;
	}
}

// void	rotate_left(t_game *game, t_player *player)
// {}

// void	rotate_right(t_game *game, t_player *player)
// {}