#include "cub3d.h"

void	print_arr(int *arr)
{
	int	i;

	i = 0;
	while (i < 3)
		printf("%d ", arr[i++]);
	printf("\n");
}

void	print_map(t_game *game)
{
	int	i;

	printf("south: %s\n", game->data->south);
	printf("north: %s\n", game->data->north);
	printf("west: %s\n", game->data->west);
	printf("east: %s\n", game->data->east);
	printf("floor: ");
	print_arr(game->data->floor);
	printf("ceiling: ");
	print_arr(game->data->ceiling);
	i = 0;
	while (game->data->map[i])
		printf("%s\n", game->data->map[i++]);
}

void	err_alloc(char *mapstr, char *buf, char *tmp)
{
	if (mapstr)
		free (mapstr);
	if (buf)
		free (buf);
	if (tmp)
		free (tmp);
	exit (0);
}

void	assign_values(t_game *game)
{
	game->data->north = "./assets/North.xpm";
	game->data->south = "./assets/South.xpm";
	game->data->west = "./assets/West.xpm";
	game->data->east = "./assets/East.xpm";
	game->data->floor[0] = 220;
	game->data->floor[1] = 100;
	game->data->floor[2] = 0;
	game->data->ceiling[0] = 225;
	game->data->ceiling[1] = 30;
	game->data->ceiling[2] = 0;
}

// void	read_map(t_game *game, char *file)
// {
// 	char	*mapstr;
// 	char	*buf;
// 	char	*tmp;
// 	int		fd;

// 	fd = open(file, O_RDONLY);
// 	mapstr = (char *)ft_calloc(1, sizeof(char));
// 	buf = (char *)ft_calloc(2, sizeof(char));
// 	if (!mapstr || !buf)
// 		err_alloc(mapstr, buf, NULL);
// 	while (read(fd, buf, 1) > 0)
// 	{
// 		tmp = mapstr;
// 		mapstr = ft_strjoin(tmp, buf);
// 		if (!mapstr)
// 			err_alloc(NULL, buf, tmp);
// 		free_ptr(tmp);
// 	}
// 	free_ptr(buf);
// 	game->data->map = ft_split(mapstr, '\n');
// 	if (!game->data->map)
// 		err_alloc(mapstr, NULL, NULL);
// 	free_ptr(mapstr);
// 	close(fd);
// 	assign_values(game);
// }
