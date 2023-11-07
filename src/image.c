#include "cub3d.h"
#include <errno.h>

int	assign_assets(t_game *game)
{
	int	w;
	int	h;

	game->assets.north = mlx_xpm_file_to_image(game->mlx_ptr, game->data->coord[0], &w, &h);
	game->assets.south = mlx_xpm_file_to_image(game->mlx_ptr, game->data->coord[1], &w, &h);
	// game->assets.west = mlx_xpm_file_to_image(game->mlx_ptr, game->data.west, &w, &h);
	game->assets.east = mlx_xpm_file_to_image(game->mlx_ptr, game->data->coord[3], &w, &h);
	if (!game->assets.north || !game->assets.south || !game->assets.east)
    {
        printf("%s = %p\n", game->data->north, game->assets.north);
        printf("%s = %p\n", game->data->south, game->assets.south);
        printf("%s = %p\n", game->data->east, game->assets.east);
        printf("freeing game\n");
		free_game(game);
    }
	return (1);
}

void	*set_tiles(t_game *game, void *ptr, int x, int y)
{
	if (game->data->map[y][x] == '1')
		ptr = game->assets.north;
	else if (game->data->map[y][x] == '0')
		ptr = game->assets.south;
	else if (game->data->map[y][x] == 'N')
		ptr = game->assets.east;
	return (ptr);
}

void	generate_tilemap(t_game *game)
{
	int		i;
	int		j;
	void	*ptr;

	assign_assets(game);
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
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, ptr, \
			PIXEL * j, PIXEL * i);
			j++;
		}
		i++;
	}
}
