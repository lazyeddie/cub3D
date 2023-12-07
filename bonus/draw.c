/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <aapostol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:26:31 by aapostol          #+#    #+#             */
/*   Updated: 2023/12/05 20:47:36 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_walls(t_game *game, t_rays *rays, int i)
{
	int	color;

	color = 0;
	rays->wall_bottom = rays->wall_size / 2 + game->win.h / 2;
	if (rays->wall_bottom > game->win.h)
		rays->wall_bottom = game->win.h;
	while (rays->wall_top <= rays->wall_bottom)
	{
		rays->tex_y = (int)rays->tex % PIXEL;
		rays->tex += rays->tex_size;
		if (rays->vertical == true && rays->dir_y > 0)
			color = draw_tex(game, rays, 'N');
		else if (rays->vertical == true && rays->dir_y <= 0)
			color = draw_tex(game, rays, 'S');
		else if (rays->vertical == false && rays->dir_x <= 0)
			color = draw_tex(game, rays, 'E');
		else if (rays->vertical == false && rays->dir_x > 0)
			color = draw_tex(game, rays, 'W');
		draw_pixel(game, i, rays->wall_top, color);
		rays->wall_top++;
	}
}

int	draw_tex(t_game *game, t_rays *rays, char tex)
{
	t_img	tmp;
	int		color;

	color = 0;
	if (tex == 'N')
		tmp = game->assets.north;
	else if (tex == 'S')
		tmp = game->assets.south;
	else if (tex == 'E')
		tmp = game->assets.east;
	else if (tex == 'W')
		tmp = game->assets.west;
	color = *(int *)(tmp.addr + (rays->tex_y * \
					tmp.lsize + rays->tex_x * (tmp.bpp / 8)));
	return (color);
}

void	draw_bg(t_game *game)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	color = game->data->hex_sky;
	while (y < game->win.h)
	{
		x = 0;
		if (y > game->win.h / 2)
			color = game->data->hex_floor;
		while (x < game->win.w)
		{
			draw_pixel(game, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_pixel(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < game->win.w && y >= 0 && y < game->win.h)
	{
		pixel = game->addr + (y * game->lsize + x * (game->bpp / 8));
		*(int *)pixel = color;
	}
}

void	draw_game(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img);
	game->img = mlx_new_image(game->mlx_ptr, game->win.w, game->win.h);
	draw_bg(game);
	raycasting(game);
	minimap(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win.ptr, game->img, 0, 0);
}
