#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# include "ft_printf.h"
# include "libft.h"
# include "structs.h"
# include "parsing.h"

//window.c
void	create_window(t_game *game);

// free_funcs.c
void	*free_ptr(void *ptr);
void	*free_array(char **arr);
void	free_game(t_game *game);

#endif