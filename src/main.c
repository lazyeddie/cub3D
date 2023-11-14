#include "cub3d.h"

void	init_struct(t_game *game, t_data *data)
{
	ft_bzero(game, sizeof(t_game));
	ft_bzero(data, sizeof(t_data));
	game->data = data;
	game->win.w = 1920;
	game->win.h = 1020;
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_data		data;
	t_player	player;
	char		*err;

	if (argc == 2)
	{
		init_struct(&game, &data);
		parsing(&game, game.data, argv[1]);
		spawn_player(&game, &player);
		err = create_window(&game);
		free_game(&game, err);
	}
	return (0);
}
