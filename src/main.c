/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <aapostol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:21:26 by aapostol          #+#    #+#             */
/*   Updated: 2023/11/26 18:21:27 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_game *game, t_data *data)
{
	ft_bzero(game, sizeof(t_game));
	ft_bzero(data, sizeof(t_data));
	game->data = data;
	game->win.w = 1920;
	game->win.h = 1020;
	game->rays = ft_calloc(game->win.w, sizeof(t_rays));
	if (!game->rays)
		free_game(game, ERR_MALLOC);
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_data		data;
	char		*err;

	if (argc == 2)
	{
		init_struct(&game, &data);
		parsing(&game, game.data, argv[1]);
		spawn_player(&game, &game.player);
		err = create_window(&game);
		free_game(&game, err);
	}
	return (0);
}
