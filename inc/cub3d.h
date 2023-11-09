#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "mlx.h"

# include "ft_printf.h"
# include "libft.h"
# include "structs.h"
# include "parsing.h"

# define PIXEL 120
# define BLUE 0x0000FF
# define GREEN 0x00FF00

// error msg
# define ERR_MALLOC "memory allocation failed\n"

// main.c
void	init_struct(t_game *game, t_data *data);

// read_map.c
void	read_map(t_game *game, char *file);
void	print_map(t_game *game);
void	assign_values(t_game *game);

// image.c
void	generate_tilemap(t_game *game);
void	draw_bg(t_game *game);

// window.c
char    *create_window(t_game *game);

// free_funcs.c
void	*free_ptr(void *ptr);
void	*free_array(char **arr);
void	free_game(t_game *game, char *msg);
t_data	*free_data(t_data *data);

#endif