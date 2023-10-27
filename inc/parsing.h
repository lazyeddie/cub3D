#ifndef PARSING_H
# define PARSING_H
# include <sys/stat.h>
# include <fcntl.h>

# include "cub3d.h"

# define READ_SIZE 10000

/*parsing.c*/
void	parsing(t_data *data, char *arg);

/*data_create.c*/
int		data_create(t_data *data, char *file);

/*data_gnl.c*/
char	*get_next_line(int fd);


#endif