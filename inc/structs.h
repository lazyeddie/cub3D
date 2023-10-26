#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_data
{
	char		**input;
	char		**map;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			*floor;
	int			*ceiling;
}	t_data;

typedef struct s_game
{
	t_data		*data;
	void		*mlx_ptr;
	void		*win_ptr;
}	t_game;

#endif