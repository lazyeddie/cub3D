/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:18:56 by rpinchas          #+#    #+#             */
/*   Updated: 2023/12/06 12:54:46 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define BLACK 0x000000
#define VIEW 6
#define OFFSET 50
#define SCALE 12

void	minimap_bg(t_game *game, t_bonus *mini, bool frame)
{
	int	x;
	int	y;

	y = mini->ymin;
	while (y < mini->ymax)
	{
		x = mini->xmin;
		while (x < mini->xmax)
		{
			if (frame && (x < mini->xmin + VIEW - 1 || \
			x > mini->xmax - VIEW || y < mini->ymin + VIEW - 1 || \
			y > mini->ymax - VIEW))
				draw_pixel(game, x, y, BLACK);
			else if (!frame)
				draw_pixel(game, x, y, GREY);
			x++;
		}
		y++;
	}
}

void	show_player(t_game *game, t_bonus *mini)
{
	mini->x = OFFSET + (mini->px - mini->x0) * SCALE;
	mini->y = OFFSET + (mini->py - mini->y0) * SCALE;
	draw_tile(game, &game->minimap, RED);
	if (game->player.dir_x >= -0.7 && game->player.dir_x <= 0.7)
	{
		if (game->player.plane_x >= 0)
			draw_dir(game, mini->x, mini->y - 10, 'N');
		else
			draw_dir(game, mini->x, mini->y + 10, 'S');
	}
	else if (game->player.dir_y >= -0.7 && game->player.dir_y <= 0.7)
	{
		if (game->player.plane_y >= 0)
			draw_dir(game, mini->y + 10, mini->x, 'W');
		else
			draw_dir(game, mini->y - 10, mini->x, 'E');
	}
}

void	show_map(t_game *game, t_bonus *mini)
{
	int	x;
	int	y;

	x = mini->x0;
	while (x <= mini->px + VIEW)
	{
		y = mini->y0;
		while (y <= mini->py + VIEW)
		{
			if (x >= 0 && x < game->data->width && \
				y >= 0 && y < game->data->height)
			{
				mini->x = OFFSET + (x - mini->x0) * SCALE;
				mini->y = OFFSET + (y - mini->y0) * SCALE;
				if (game->data->map[y][x] == '1')
					draw_tile(game, mini, GREEN);
				else if (game->data->map[y][x] == '0')
					draw_tile(game, mini, WHITE);
			}
			y++;
		}
		x++;
	}
}

void	init_mini(t_game *game, t_bonus *mini)
{
	mini->px = (int)game->player.pos_x;
	mini->py = (int)game->player.pos_y;
	mini->x0 = mini->px - VIEW;
	mini->y0 = mini->py - VIEW;
	mini->xmax = OFFSET + (mini->px + VIEW + 1 - mini->x0) * SCALE;
	mini->ymax = OFFSET + (mini->py + VIEW + 1 - mini->y0) * SCALE;
	mini->ymin = OFFSET + (mini->y0 - mini->y0 - 1) * SCALE;
	mini->xmin = OFFSET + (mini->x0 - mini->x0 - 1) * SCALE;
}

void	minimap(t_game	*game)
{
	init_mini(game, &game->minimap);
	minimap_bg(game, &game->minimap, 0);
	show_map(game, &game->minimap);
	show_player(game, &game->minimap);
	minimap_bg(game, &game->minimap, 1);
}
