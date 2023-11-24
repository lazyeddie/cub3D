#include "cub3d.h"

int	texture_size_check(t_assets tex)
{
	return (tex.north.px_w != tex.north.px_h || tex.east.px_w != tex.east.px_h \
	|| tex.south.px_w != tex.south.px_h || tex.west.px_w != tex.west.px_h || \
		tex.north.px_w != tex.east.px_w || tex.north.px_w != tex.south.px_h || \
		tex.north.px_w != tex.west.px_w);
}


void	load_map(t_game *game)
{
	game->assets.north.mlx_img = assign_asset(game, &game->assets.north, game->data->north);
	game->assets.west.mlx_img = assign_asset(game, &game->assets.west, game->data->west);
	game->assets.east.mlx_img = assign_asset(game, &game->assets.east, game->data->east);
	game->assets.south.mlx_img = assign_asset(game, &game->assets.south, game->data->south);
	if (texture_size_check(game->assets))
		free_game(game, "Textures have wrong size!");
	game->pixel = game->assets.north.px_w;
}

void	*assign_asset(t_game *game, t_img *asset, char *path)
{
	asset->mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, path, &asset->px_w, &asset->px_h);
	if (!asset->mlx_img)
		free_game(game, ERR_MALLOC);
	asset->addr = mlx_get_data_addr(asset->mlx_img, &asset->bpp, &asset->lsize,
			&asset->endian);
	if (!asset->addr)
		free_game(game, ERR_MALLOC);
	return (asset->mlx_img);
}

// void	*set_tiles(t_game *game, void *ptr, int x, int y)
// {
// 	if (game->data->map[y][x] == '1')
// 		ptr = game->assets.north.mlx_img;
// 	// else if (game->data->map[y][x] == '0')
// 	// 	ptr = game->assets.empty.mlx_img;
// 	// else if (game->data->map[y][x] == 'N')
// 	// 	ptr = game->assets.player.mlx_img;
// 	else
// 		ptr = game->assets.north.mlx_img;
// 	return (ptr);
// }

// void	generate_tilemap(t_game *game)
// {
// 	int		i;
// 	int		j;
// 	void	*ptr;

// 	load_map(game);
// 	ptr = NULL;
// 	i = 0;
// 	while (game->data->map[i])
// 	{
// 		j = 0;
// 		while (game->data->map[i][j])
// 		{
// 			ptr = set_tiles(game, ptr, j, i);
// 			if (!ptr)
// 				free_game(game, "test\n");
// 			mlx_put_image_to_window(game->mlx_ptr, game->win.ptr, ptr, 
// 			PIXEL * j, PIXEL * i);
// 			j++;
// 		}
// 		i++;
// 	}
// }
