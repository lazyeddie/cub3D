#include "cub3d.h"

// ft_error()
// {

// }

void	free_game(t_game *game)
{
	if (game->assets.north.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->assets.north.mlx_img);
	if (game->assets.south.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->assets.south.mlx_img);
	if (game->assets.west.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->assets.west.mlx_img);
	if (game->assets.east.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->assets.east.mlx_img);
	if (game->assets.player.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->assets.player.mlx_img);
	if (game->assets.empty.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->assets.empty.mlx_img);
	mlx_destroy_window(game->mlx_ptr, game->win.ptr);
	mlx_destroy_display(game->mlx_ptr);
	game->mlx_ptr = free_ptr(game->mlx_ptr);
	game->data->map = free_array(game->data->map);
}

void	*free_array(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free_ptr(arr[i++]);
		arr = free_ptr(arr);
	}
	return (arr);
}

void	*free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
	return (ptr);
}
