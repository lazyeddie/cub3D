#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_data
{
	char		*input;
	int			count[6];
	char		**map;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			floor[3];
	int			ceiling[3];
}	t_data;

typedef struct s_assets
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
}	t_assets;

typedef struct s_game
{
	int			fd;
	t_data		*data;
	t_assets	assets;
	void		*mlx_ptr;
	void		*win_ptr;
}	t_game;

#endif