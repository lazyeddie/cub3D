#include "cub3d.h"

int	ft_ceil(float num)
{
	int	i;

	i = (int)num;
	if (num > 0 && num > i)
		return (i + 1);
	if (num < 0 && num < i)
		return (i - 1);
	return (i);
}

void	move_player(t_game *game, t_player *player, int keysym)
{
	if (keysym == XK_w)
		move_forward(game, player);
	else if (keysym == XK_s)
		move_backward(game, player);
	else if (keysym == XK_a)
		move_sideways(game, player, LEFT);
	else if (keysym == XK_d)
		move_right(game, player);
	else if (keysym == XK_Left)
		rotate_left(player);
	else if (keysym == XK_Right)
	 	rotate_right(player);
}

void	move_forward(t_game *game, t_player *player)
{
	player->next_x = player->pos_x + ft_ceil(player->dir_x);
	player->next_y = player->pos_y + ft_ceil(player->dir_y);
	if (game->data->map[player->next_y][player->next_x] != '1')
	{
		player->pos_x = player->next_x;
		player->pos_y = player->next_y;
	}
}

void	move_backward(t_game *game, t_player *player)
{
	player->next_x = player->pos_x - ft_ceil(player->dir_x);
	player->next_y = player->pos_y - ft_ceil(player->dir_y);
	if (game->data->map[player->next_y][player->next_x] != '1')
	{
		player->pos_x = player->next_x;
		player->pos_y = player->next_y;
	}
}

void	move_sideways(t_game *game, t_player *player, int mov_dir)
{
	player->next_x = player->pos_x - ft_ceil(player->plane_x);
	player->next_y = player->pos_y - ft_ceil(player->plane_y);
	if (game->data->map[player->next_y][player->next_x] != '1')
	{
		player->pos_x = player->next_x;
		player->pos_y = player->next_y;
	}
}

void	move_right(t_game *game, t_player *player)
{
	player->next_x = player->pos_x + ft_ceil(player->plane_x);
	player->next_y = player->pos_y + ft_ceil(player->plane_y);
	if (game->data->map[player->next_y][player->next_x] != '1')
	{
		player->pos_x = player->next_x;
		player->pos_y = player->next_y;
	}
}

void	rotate_left(t_player *player)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(ROTATION_SPEED) - player->dir_y * sin(ROTATION_SPEED);
	player->dir_y = old_dir_x * sin(ROTATION_SPEED) + player->dir_y * cos(ROTATION_SPEED);
	player->plane_x = player->plane_x * cos(ROTATION_SPEED) - player->plane_y * sin(ROTATION_SPEED);
	player->plane_y = old_plane_x * sin(ROTATION_SPEED) + player->plane_y * cos(ROTATION_SPEED);
}

void	rotate_right(t_player *player)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(-ROTATION_SPEED) - player->dir_y * sin(-ROTATION_SPEED);
	player->dir_y = old_dir_x * sin(-ROTATION_SPEED) + player->dir_y * cos(-ROTATION_SPEED);
	player->plane_x = player->plane_x * cos(-ROTATION_SPEED) - player->plane_y * sin(-ROTATION_SPEED);
	player->plane_y = old_plane_x * sin(-ROTATION_SPEED) + player->plane_y * cos(-ROTATION_SPEED);
}