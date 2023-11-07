#include "cub3d.h"
#include <errno.h>

// int	assign_assets(t_game *game)
// {
// 	int	w;
// 	int	h;

// 	game->assets.player = mlx_xpm_file_to_image(game->mlx_ptr, game->data->player, &w, &h);
// 	game->assets.north = mlx_xpm_file_to_image(game->mlx_ptr, game->data->north, &w, &h);
// 	game->assets.south = mlx_xpm_file_to_image(game->mlx_ptr, game->data->south, &w, &h);
// 	// game->assets.west = mlx_xpm_file_to_image(game->mlx_ptr, game->data.west, &w, &h);
// 	game->assets.east = mlx_xpm_file_to_image(game->mlx_ptr, game->data->east, &w, &h);
// 	if (!game->assets.north || !game->assets.south || !game->assets.east)
//     {
//         printf("%s = %p\n", game->data->north, game->assets.north);
//         printf("%s = %p\n", game->data->south, game->assets.south);
//         printf("%s = %p\n", game->data->east, game->assets.east);
//         printf("freeing game\n");
// 		free_game(game);
//     }
// 	return (1);
// }

void	*assign_asset(t_game *game, void *asset_ptr, char *path)
{
	int	w;
	int	h;

	asset_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, &w, &h);
	if (!asset_ptr)
	{
		free_game(game);
		// exit (1);
	}
	return (asset_ptr);
}

void	*set_tiles(t_game *game, void *ptr, int x, int y)
{
	if (game->data->map[y][x] == '1')
		ptr = game->assets.north.mlx_img;
	else if (game->data->map[y][x] == '0')
		ptr = game->assets.empty.mlx_img;
	else if (game->data->map[y][x] == 'N')
		ptr = game->assets.player.mlx_img;
	return (ptr);
}

void	load_map(t_game *game)
{
	game->assets.north.mlx_img = assign_asset(game, &game->assets.north.mlx_img, game->data->north);
	game->assets.player.mlx_img = assign_asset(game, &game->assets.player.mlx_img, game->data->player);
	game->assets.empty.mlx_img = assign_asset(game, &game->assets.empty.mlx_img, game->data->empty);
	// assign_asset(game, &game->assets.west.mlx_img, game->data->west);
	// assign_asset(game, &game->assets.east.mlx_img, game->data->east);
	// assign_asset(game, &game->assets.south.mlx_img, game->data->south);
}

void	draw_bg(t_game *game)
{
	int		x;
	int		y;
	char	*pixel;
	int		color;

	y = 0;
	color = BLUE;
	while (y < game->win.h)
	{
		x = 0;
		if (y > game->win.h / 2)
			color = GREEN;
		while (x < game->win.w)
		{
			pixel = game->addr + (y * game->win.w + x) * 4;
			*(int *)pixel = color;
			x++;
		}
		y++;
	}
}

void	generate_tilemap(t_game *game)
{
	int		i;
	int		j;
	void	*ptr;

	// assign_assets(game);
	load_map(game);
	ptr = NULL;
	i = 0;
	while (game->data->map[i])
	{
		j = 0;
		while (game->data->map[i][j])
		{
			ptr = set_tiles(game, ptr, j, i);
			if (!ptr)
			{
				free_game(game);
				return ;
			}
			mlx_put_image_to_window(game->mlx_ptr, game->win.ptr, ptr, \
			PIXEL * j, PIXEL * i);
			j++;
		}
		i++;
	}
}
