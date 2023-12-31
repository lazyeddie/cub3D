/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:36:57 by aapostol          #+#    #+#             */
/*   Updated: 2023/12/06 18:32:57 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_data
{
	char		*input;
	int			count[6];
	char		**map;
	int			height;
	int			width;
	char		*assarr[6];
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*player;
	int			valid_player;
	char		*empty;
	int			floor[3];
	int			hex_floor;
	int			ceiling[3];
	int			hex_sky;
}	t_data;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		px_w;
	int		px_h;
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

typedef struct s_rays
{
	float	fov;
	float	pov_x;
	float	pov_y;
	float	dir_x;
	float	dir_y;
	float	delta_x;
	float	delta_y;
	int		grid_x;
	int		grid_y;
	float	step_dir_x;
	float	step_dir_y;
	float	step_dist_x;
	float	step_dist_y;
	bool	vertical;
	bool	wall;
	float	wall_dist;
	float	wall_size;
	float	wall_top;
	float	wall_bottom;
	float	wall_slice;
	float	tex;
	float	tex_size;
	int		tex_x;
	int		tex_y;
}	t_rays;

typedef struct s_bonus
{
	int		x;
	int		y;
	int		x0;
	int		y0;
	int		px;
	int		py;
	int		xmax;
	int		ymax;
	int		xmin;
	int		ymin;
}	t_bonus;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	int		next_x;
	int		next_y;
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
	t_assets	assets;
	t_player	player;
	t_bonus		minimap;
	t_rays		*rays;
	int			pixel;
	void		*img;
	char		*addr;
	int			bpp;
	int			lsize;
	int			endian;
	void		*mlx_ptr;
}	t_game;

#endif