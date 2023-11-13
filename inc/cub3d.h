#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include <stdbool.h>
# include "mlx.h"

# include "ft_printf.h"
# include "libft.h"
# include "structs.h"
# include "parsing.h"

# define PIXEL 120
# define BLUE 0x4f84c9
# define GREEN 0x1a3d0d

// error msg
# define ERR_MALLOC "memory allocation failed\n"
# define ERR_PLAYER "there must be exactly one player\n"

// main.c
void	init_struct(t_game *game, t_data *data);

// read_map.c
void	read_map(t_game *game, char *file);
void	print_map(t_game *game);
void	assign_values(t_game *game);

// player.c
void	spawn_player(t_game *game, t_player *player);
void	get_player_pos(t_game *game, char **map, t_player *player);
void	set_start_dir(t_player *player);

// raycasting.c
void	raycasting(t_game *game);
void	set_ray_direction(t_game *game, t_rays *rays, t_player player, int i);
void	calculate_steps(t_rays *rays);
void	find_wall(t_rays *rays, char **map);

// moves.c
void	move_player(t_game *game, int keysym);

// image.c
void	draw_bg(t_game *game);
void	load_map(t_game *game);
void	*assign_asset(t_game *game, void *asset_ptr, char *path);

// window.c
char	*create_window(t_game *game);

// free_funcs.c
void	*free_ptr(void *ptr);
void	*free_array(char **arr);
void	free_game(t_game *game, char *msg);
t_data	*free_data(t_data *data);

#endif