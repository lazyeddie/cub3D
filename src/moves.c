#include "cub3d.h"

void	move_player(t_game *game, t_player *player, int keysym)
{
	if (keysym == XK_w)
		move_forward(game, player);
	else if (keysym == XK_s)
		move_backward(game, player);
	else if (keysym == XK_a)
		move_sideways(game, player, LEFT);
	else if (keysym == XK_d)
		move_sideways(game, player, RIGHT);
	// else if (keysym == XK_Left)
	// 	rotate_left(game, player);
	// else if (keysym == XK_Right)
	// 	rotate_right(game, player);
}

void	move_forward(t_game *game, t_player *player)
{
	float	move_x;
	float	move_y;

	move_x = STEP * (float)player->dir_x;
	move_y = STEP * (float)player->dir_y;
	player->next_x = (int)(player->pos_x + move_x);
	player->next_y = (int)(player->pos_y + move_y);
	if (game->data->map[player->next_y][player->next_x] && \
		game->data->map[player->next_y][player->next_x] != '1')
	{
		player->pos_x = player->next_x;
		player->pos_y = player->next_y;
	}
}

void	move_backward(t_game *game, t_player *player)
{
	float	move_x;
	float	move_y;

	move_x = -STEP * (float)player->dir_x;
	move_y = -STEP * (float)player->dir_y;
	player->next_x = (int)(player->pos_x + move_x);
	player->next_y = (int)(player->pos_y + move_y);
	if (game->data->map[player->next_y][player->next_x] && \
		game->data->map[player->next_y][player->next_x] != '1')
	{
		player->pos_x = player->next_x;
		player->pos_y = player->next_y;
	}
}

void	move_sideways(t_game *game, t_player *player, int mov_dir)
{
	float	move_x;
	float	move_y;

	move_x = STEP * (float)player->plane_x;
	move_y = STEP * (float)player->plane_y;
	if (mov_dir == LEFT)
	{
		move_x = -move_x;
		move_y = -move_y;
	}
	player->next_x = player->pos_x + move_x;
	player->next_y = player->pos_y + move_y;
	if (game->data->map[player->next_y][player->next_x] && \
		game->data->map[player->next_y][player->next_x] != '1')
	{
		player->pos_x = player->next_x;
		player->pos_y = player->next_y;
	}
}


// void	rotate_left(t_game *game, t_player *player)
// {}

// void	rotate_right(t_game *game, t_player *player)
// {}