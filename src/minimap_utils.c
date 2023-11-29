#include "cub3d.h"

void	draw_dir(t_game *game, int x0, int y0, int dir)
{
	int	x;
	int	y;
	int	i;

	y = y0 - 5;
	i = 5;
	while (y <= (y0 + 5))
	{
		x = x0 - 5;
		while (x <= (x0 + 5))
		{
			if (dir == 'N' && x <= (x0 - i) && x >= (x0 + i))
				draw_pixel(game, x, y, BLUE);
			if (dir == 'S' && x >= (x0 - i) && x <= (x0 + i))
				draw_pixel(game, x, y, BLUE);
			if (dir == 'E' && x >= (x0 - i) && x >= (x0 + i))
				draw_pixel(game, x, y, BLUE);
			if (dir == 'W' && x <= (x0 - i) && x <= (x0 + i))
				draw_pixel(game, x, y, BLUE);
			x++;
		}
		y++;
		i--;
	}
}

void	draw_tile(t_game *game, t_bonus *mini, int color)
{
	int	x;
	int	y;

	y = mini->y - 5;
	while (y < (mini->y + 5))
	{
		x = mini->x - 5;
		while (x < (mini->x + 5))
		{
			draw_pixel(game, x, y, color);
			x++;
		}
		y++;
	}
}
