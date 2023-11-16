#include "cub3d.h"

void	draw_walls(t_game *game, t_rays *rays, int i)
{
	rays->wall_bottom =  rays->wall_size / 2 + game->win.h / 2;
	if (rays->wall_bottom > game->win.h)
		rays->wall_bottom = game->win.h;
	// print_rays(game->rays[i], i);
	while (rays->wall_top <= rays->wall_bottom)
	{
		rays->tex_y = (int)rays->tex % PIXEL;
		rays->tex += rays->tex_size;
		if (rays->vertical == 1 && rays->dir_y <= 0)
			draw_tex(game, i, rays->wall_top, 'N');
		else if (rays->vertical == 1 && rays->dir_y > 0)
			draw_tex(game, i, rays->wall_top, 'S');
		else if (rays->vertical == 0 && rays->dir_x > 0)
			draw_tex(game, i, rays->wall_top, 'E');
		else if (rays->vertical == 0 && rays->dir_x <= 0)
			draw_tex(game, i, rays->wall_top, 'W');
		rays->wall_top++;
		// printf("rays->vertical: %d, rays->dir_x: %f, rays->dir_y: %f\n", rays->vertical, rays->dir_x, rays->dir_y);
	}
}

void	draw_tex(t_game *game, int x, int y, char tex)
{
	int		color;
	t_img	tmp;

	color = 0;
	if (tex == 'N')
		tmp = game->assets.north;
	else if (tex == 'S')
		tmp = game->assets.south;
	else if (tex == 'E')
		tmp = game->assets.east;
	else if (tex == 'W')
		tmp = game->assets.west;
	color = *(int *)(tmp.addr + (game->rays->tex_y * 
					tmp.lsize + game->rays->tex_x * (tmp.bpp / 8)));
	draw_pixel(game, x, y, color);
}

void	draw_bg(t_game *game)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	color = CEILING;
	while (y < game->win.h)
	{
		x = 0;
		if (y > game->win.h / 2)
			color = FLOOR;
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
	mlx_put_image_to_window(game->mlx_ptr, game->win.ptr, game->img, 0, 0);
}
