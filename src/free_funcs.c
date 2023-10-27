#include "cub3d.h"

void	free_game(t_game *game)
{
	if (game->assets.north)
		mlx_destroy_image(game->mlx_ptr, game->assets.north);
	if (game->assets.south)
		mlx_destroy_image(game->mlx_ptr, game->assets.south);
	// if (game->assets.west)
	// 	mlx_destroy_image(game->mlx_ptr, game->assets.west);
	if (game->assets.east)
		mlx_destroy_image(game->mlx_ptr, game->assets.east);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	game->mlx_ptr = free_ptr(game->mlx_ptr);
	game->map = free_array(game->map);
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
