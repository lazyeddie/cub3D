#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_data
{
	char		*input;
	int			count[6];
	char		**map;
	char		*assarr[6];
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*player;
	char		*empty;
	int			floor[3];
	int			ceiling[3];
}	t_data;

typedef struct s_img
{
	void	*mlx_img;
	char	*img_addr;
	int		bpp;
	int		lsize;
	int		endian;

}	t_img;

typedef struct s_assets
{
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
}	t_assets;

typedef enum e_moves
{
	FRONT,
	BACK,
	LEFT,
	RIGHT,
	ROT_LEFT,
	ROT_RIGHT	
}	t_moves;

typedef struct s_rays
{
	float	fov;
	float	pov_x;
	float	pov_y;
	float	dir_x;
	float	dir_y;
	float	delta_x;
	float	delta_y;
	float	grid_x;
	float	grid_y;
	float	step_dir_x;
	float	step_dir_y;
	float	step_dist_x;
	float	step_dist_y;
	bool	vertical;
	bool	wall;
	float	wall_dist;
	float	wall_size;
	float	wall_top;
	float	wall_slice;
	float	tex;
	float	tex_size;
	float	tex_slice; 
}	t_rays;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	char	start_dir;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
}	t_player;

typedef struct s_win
{
	int		w;
	int		h;
	void	*ptr;
}	t_win;
typedef struct s_game
{
	int			fd;
	t_data		*data;
	t_win		win;
	void		*img;
	char		*addr;
	t_assets	assets;
	t_player	player;
	t_rays		*rays;
	t_moves		move;
	int			bpp;
	int			lsize;
	int			endian;
	void		*mlx_ptr;
}	t_game;

#endif