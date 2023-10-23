#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_game
{
	char		**map;
	void		*mlx_ptr;
	void		*win_ptr;
}	t_game;

//window.c
void	create_window(t_game *game);

// free_funcs.c
void	*free_ptr(void *ptr);
void	*free_array(char **arr);
void	free_game(t_game *game);

#endif