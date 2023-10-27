#include "cub3d.h"

void	init_struct(t_game *game, t_data *data)
{
	game->data = data;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_data	data;

	if (argc == 2)
	{
		init_struct(&game, &data);
		parsing(game.data, argv[1]);
		create_window(&game);
	}
	return (0);
}
