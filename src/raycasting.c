/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:30:38 by aapostol          #+#    #+#             */
/*   Updated: 2023/12/06 13:01:39 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->win.w)
	{
		set_ray_direction(game, &game->rays[i], game->player, i);
		calculate_steps(&game->rays[i]);
		find_wall(game, &game->rays[i], game->data->map);
		calculate_wall(game, &game->rays[i], &game->player);
		draw_walls(game, &game->rays[i], i);
		i++;
	}
}

void	set_ray_direction(t_game *game, t_rays *rays, t_player player, int i)
{
	rays->grid_x = (int)player.pos_x;
	rays->grid_y = (int)player.pos_y;
	rays->pov_x = player.pos_x;
	rays->pov_y = player.pos_y;
	rays->fov = 2.0 * i / (float)game->win.w - 1.0;
	rays->dir_x = player.dir_x + player.plane_x * rays->fov;
	rays->dir_y = player.dir_y + player.plane_y * rays->fov;
	if (rays->dir_x == 0)
		rays->delta_x = 10000000;
	else
		rays->delta_x = fabs(1.0 / rays->dir_x);
	if (rays->dir_y == 0)
		rays->delta_y = 10000000;
	else
		rays->delta_y = fabs(1.0 / rays->dir_y);
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
		rays->step_dist_y = (rays->pov_y - rays->grid_y) * rays->delta_y;
	}
	else
	{
		rays->step_dir_y = 1;
		rays->step_dist_y = (rays->grid_y + 1.0 - rays->pov_y) * rays->delta_y;
	}
}

void	find_wall(t_game *game, t_rays *rays, char **map)
{
	rays->wall = false;
	while (!rays->wall)
	{
		if (rays->step_dist_x < rays->step_dist_y)
		{
			rays->step_dist_x += rays->delta_x;
			rays->grid_x += rays->step_dir_x;
			rays->vertical = false;
		}
		else
		{
			rays->step_dist_y += rays->delta_y;
			rays->grid_y += rays->step_dir_y;
			rays->vertical = true;
		}
		if (rays->grid_x < 0 || rays->grid_y < 0 || rays->grid_x >= \
			game->data->width || rays->grid_y >= game->data->height || \
			map[(int)rays->grid_y][(int)rays->grid_x] == '1')
			rays->wall = true;
	}
	if (rays->vertical == false)
		rays->wall_dist = rays->step_dist_x - rays->delta_x;
	else
		rays->wall_dist = rays->step_dist_y - rays->delta_y;
}

void	calculate_wall(t_game *game, t_rays *rays, t_player *player)
{
	(void)player;
	rays->wall_size = game->win.h / (rays->wall_dist);
	rays->wall_top = -rays->wall_size / 2.0 + game->win.h / 2.0;
	if (rays->wall_top < 0)
		rays->wall_top = 0;
	if (rays->vertical)
		rays->wall_slice = rays->pov_x + rays->wall_dist * rays->dir_x;
	else
		rays->wall_slice = rays->pov_y + rays->wall_dist * rays->dir_y;
	rays->wall_slice -= floor(rays->wall_slice);
	rays->tex_size = (float)game->pixel / (float)rays->wall_size;
	rays->tex_x = (int)(rays->wall_slice * game->pixel);
	if ((rays->vertical == false && rays->dir_x < 0) || \
		(rays->vertical == true && rays->dir_y > 0))
		rays->tex_x = game->pixel - rays->tex_x - 1;
	rays->tex = (rays->wall_top - game->win.h / 2 + \
				rays->wall_size / 2) * rays->tex_size;
}
