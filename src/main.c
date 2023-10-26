#include "cub3d.h"

void	init_struct(t_game *game)
{
	game->data = NULL;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;
	char *str = "ruben";

	if (argc == 2)
	{
		init_struct(&game);
		parsing(game.data, argv[1]);
		create_window(&game);
		ft_strlen(str);
	}
	return (0);
}
