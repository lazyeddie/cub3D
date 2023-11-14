#include "cub3d.h"

int	render(t_game *game)
{
	draw_bg(game);
	raycasting(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win.ptr, game->img, 0, 0);
	return (0);
}

int	handle_buttonpress(t_game *game)
{
	free_game(game, NULL);
	return (0);
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		free_game(game, NULL);
	// else
	// 	move_player(game, keysym);
	return (0);
}

char	*create_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (ERR_MALLOC);
	game->win.ptr = mlx_new_window(game->mlx_ptr, game->win.w, game->win.h, "cub3D");
	if (!game->win.ptr)
		return (ERR_MALLOC);
	game->img = mlx_new_image(game->mlx_ptr, game->win.w, game->win.h);
	if (!game->img)
		return (ERR_MALLOC);
	game->addr = mlx_get_data_addr(game->img, &game->bpp, &game->lsize, &game->endian);
	load_map(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win.ptr, game->img, 0, 0);
	mlx_loop_hook(game->mlx_ptr, &render, game);
	mlx_hook(game->win.ptr, KeyPress, KeyPressMask, &handle_keypress, game);
	mlx_hook(game->win.ptr, 17, 0, &handle_buttonpress, game);
	mlx_loop(game->mlx_ptr);
	return (NULL);
}
