#include "cub3d.h"

void	raycasting(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->win.w)
	{
		set_ray_direction(game, game->rays, game->player, i);
		calculate_steps(game->rays);
		find_wall(game->rays, game->data->map);
		// calculate textures
		mlx_put_image_to_window(game->mlx_ptr, game->win.ptr, game->img, 0, 0);
	}
}

void	set_ray_direction(t_game *game, t_rays *rays, t_player *player, int i)
{
	rays->pov_x = player->pos_x + 0.5;
	rays->pov_y = player->pos_y + 0.5;
	rays->view = 2 * i / game->win.w - 1.0;
	rays->dir_x = player->dir_x + player->plane_x * rays->view;
	rays->dir_y = player->dir_y + player->plane_y * rays->view;
	if (rays->dir_x == 0)
		rays->delta_x = 10000000;
	else
		rays->delta_x = fabs(1.0 / rays->dir_x);
	if (rays->dir_y == 0)
		rays->delta_y = 10000000;
	else
		rays->delta_y = fabs(1.0 / rays->dir_y);
	rays->grid_x = rays->pov_x;
	rays->grid_y = rays->pov_y;
}

void	calculate_steps(t_rays *rays)
{
	if (rays->dir_x < 0)
	{
		rays->step_dir_x = -1;
		rays->step_dist_x = (rays->pov_x - rays->grid_x) * rays->delta_x;
	}
	else
	{
		rays->step_dir_x = 1;
		rays->step_dist_x = (rays->grid_x + 1.0 - rays->pov_x) * rays->delta_x;
	}
	if (rays->dir_y < 0)
	{
		rays->step_dir_y = -1;
		rays->step_dist_y = (rays->pov_y - rays->grid_y);
	}
	else
	{
		rays->step_dir_y = 1;
		rays->step_dist_y = (rays->grid_y + 1.0 - rays->pov_y) * rays->delta_y;
	}
}

void	find_wall(t_rays *rays, char **map)
{
	bool	wall;

	wall = false;
	while (!wall)
	{
		if (rays->step_dist_x < rays->step_dist_y)
		{
			rays->step_dir_x += rays->delta_x;
			rays->grid_x += rays->step_dir_x;
			rays->vertical = false;
		}
		else
		{
			rays->step_dir_y += rays->delta_y;
			rays->grid_y += rays->step_dir_y;
			rays->vertical = true;
		}
		if (map[(int)rays->grid_y][(int)rays->grid_x] == '1')
			wall = true;
	}
	if (rays->vertical == false)
		rays->wall_dist = rays->step_dist_x - rays->delta_x;
	else
		rays->wall_dist = rays->step_dist_y - rays->delta_y;
}

// void	morph_textures(t_game *game, t_rays *rays, t_player *player)
// {
// 	rays->wall_size = game->win.h / rays->wall_dist;
// 	rays->wall_center = game->win.h / 2 - rays->wall_size / 2;
// }
