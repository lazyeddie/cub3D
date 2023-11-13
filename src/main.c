#include "cub3d.h"

void	init_struct(t_game *game, t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	ft_bzero(game, sizeof(t_game));
	ft_bzero(&game->rays, sizeof(t_rays));
	game->data = data;
	game->win.w = 1920;
	game->win.h = 1020;
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_data	data;
	char	*err;

	if (argc == 2)
	{
		init_struct(&game, &data);
		parsing(&game, game.data, argv[1]);
		// assign_values(&game);
		// read_map(&game, argv[1]);
		// print_map(&game);
		spawn_player(&game, &game.player);
		err = create_window(&game);
		free_game(&game, err);
	}
	return (0);
}
