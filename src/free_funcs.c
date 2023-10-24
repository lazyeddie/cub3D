#include "cub3d.h"

void	free_game(t_game *game)
{
	(void)game;
	// if (game->graphix.wall)
	// 	mlx_destroy_image(game->mlx_ptr, game->graphix.wall);
	// if (game->graphix.zero)
	// 	mlx_destroy_image(game->mlx_ptr, game->graphix.zero);
	// if (game->graphix.player)
	// 	mlx_destroy_image(game->mlx_ptr, game->graphix.player);
	// if (game->graphix.exit)
	// 	mlx_destroy_image(game->mlx_ptr, game->graphix.exit);
	// if (game->graphix.collectible)
	// 	mlx_destroy_image(game->mlx_ptr, game->graphix.collectible);
	// if (game->graphix.empty)
	// 	mlx_destroy_image(game->mlx_ptr, game->graphix.empty);
	// mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	// mlx_destroy_display(game->mlx_ptr);
	// game->mlx_ptr = free_ptr(game->mlx_ptr);
	// game->map = free_array(game->map);
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
