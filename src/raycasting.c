#include "cub3d.h"

void	raycasting(t_game *game)
{
	int	i;

	i = 0;
	game->rays = ft_calloc(game->win.w, sizeof(t_rays));
	if (!game->rays)
		free_game(game, ERR_MALLOC);
	while (i < game->win.w)
	{
		set_ray_direction(game, &game->rays[i], game->player, i);
		// printf("i: %d, dir_x: %f\n", i, game->rays[i].dir_x);
		calculate_steps(&game->rays[i]);
		find_wall(&game->rays[i], game->data->map);
		// calculate distance
		// calculate textures
		// mlx_put_image_to_window(game->mlx_ptr, game->win.ptr, game->img, 0, 0);
		i++;
	}
}

void	set_ray_direction(t_game *game, t_rays *rays, t_player player, int i)
{
	rays->pov_x = player.pos_x + 0.5;
	rays->pov_y = player.pos_y + 0.5;
	rays->fov = 2.0 * i / game->win.w - 1.0;
	rays->dir_x = player.dir_x + player.plane_x * rays->fov;
	// printf("%f + %f * %f\n", player.dir_y, player.plane_y, rays->fov);
	rays->dir_y = player.dir_y + player.plane_y * rays->fov;
	// printf("dir_x: %f, dir_y: %f, fov: %f\n", rays->dir_x, rays->dir_y, rays->fov);
	if (rays->dir_x == 0)
		rays->delta_x = 10000000;
	else
		rays->delta_x = fabs(1.0 / rays->dir_x);
	if (rays->dir_y == 0)
		rays->delta_y = 10000000;
	else
		rays->delta_y = fabs(1.0 / rays->dir_y);
	rays->grid_x = player.pos_x;
	rays->grid_y = player.pos_y;
}

void	calculate_steps(t_rays *rays)
{
	if (rays->dir_x < 0)
	{
		rays->step_dir_x = -1.0;
		rays->step_dist_x = (rays->pov_x - rays->grid_x) * rays->delta_x;
	}
	else
	{
		rays->step_dir_x = 1.0;
		rays->step_dist_x = (rays->grid_x + 1.0 - rays->pov_x) * rays->delta_x;
	}
	if (rays->dir_y < 0)
	{
		rays->step_dir_y = -1.0;
		rays->step_dist_y = (rays->pov_y - rays->grid_y);
	}
	else
	{
		rays->step_dir_y = 1.0;
		rays->step_dist_y = (rays->grid_y + 1.0 - rays->pov_y) * rays->delta_y;
	}
	printf("calc_steps - x: %f, y: %f\n", rays->step_dist_x, rays->step_dist_y);
}

void	find_wall(t_rays *rays, char **map)
{
	bool	wall;

	wall = false;
	printf("find wall - x: %f, y: %f\n", rays->step_dist_x, rays->step_dist_y);
	while (!wall)
	{
		if (rays->step_dist_x < rays->step_dist_y)
		{
			rays->step_dir_x += rays->delta_x;
			rays->grid_x += rays->step_dir_x;
			printf("grid_x: %f\n", rays->grid_x);
			rays->vertical = false;
			// printf("horizontal\n");
		}
		else
		{
			rays->step_dir_y += rays->delta_y;
			rays->grid_y += rays->step_dir_y;
			printf("grid_y: %f\n", rays->grid_y);
			rays->vertical = true;
			// printf("vertical\n");
		}
		if (rays->grid_x < 0 || rays->grid_y < 0 || \
			rays->grid_x >= 34 || rays->grid_y >= 14 || \
			map[(int)rays->grid_y][(int)rays->grid_x] == '1')
		{
			wall = true;
			printf("wall\n");
		}
	}
}
