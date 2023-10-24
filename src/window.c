#include "cub3d.h"

// int	handle_no_event(t_game *game)
// {
// 	(void)game;
// 	return (0);
// }

// int	handle_buttonpress(t_game *game)
// {
// 	free_game(game);
// 	return (0);
// }

// int	handle_keypress(int keysym, t_game *game)
// {
// 	if (keysym == XK_Escape)
// 		free_game(game);
// 	else
// 		move_player(game, keysym);
// 	return (0);
// }

void	create_window(t_game *game)
{
	(void)game;
// 	int	win_w;
// 	int	win_h;

// 	win_w = game->size.x * PIXEL;
// 	win_h = game->size.y * PIXEL;
// 	game->mlx_ptr = mlx_init();
// 	if (!game->mlx_ptr)
// 		return ;
// 	game->win_ptr = mlx_new_window(game->mlx_ptr, win_w, win_h, "cub3D");
// 	if (!game->win_ptr)
// 	{
// 		mlx_destroy_display(game->mlx_ptr);
// 		free_ptr(game->mlx_ptr);
// 		return ;
// 	}
// 	// raycasting
// 	mlx_loop_hook(game->mlx_ptr, &handle_no_event, game);
// 	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);
// 	mlx_hook(game->win_ptr, 17, 0, &handle_buttonpress, game);
// 	mlx_loop(game->mlx_ptr);
// 	free_game(game);
}
