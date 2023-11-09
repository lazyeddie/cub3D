#ifndef PARSING_H
# define PARSING_H
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include "cub3d.h"

# define READ_SIZE 10000

typedef enum e_ret
{
	FILE_ERR = 1,
	EMPTY_ERR,
	DUP_ERR,
	INPUT_ERR,
	MAP_CHAR_ERR,
	ASSET_ERR,
	MALLOC_ERR,
	RGB_ERR,
}	t_ret;


/*data_check*/
void	skip_word(char *str, int *i, bool word);
void	skip_a(char *str, int *i, int a);
int		check_counter(int *count);
int		check_data(t_data *data, char *input);

/*data_create.c*/
int		not_valid_file(char *s1, char *s2, int n);
char	*ft_strnjoin(char const *s1, char const *s2, int len);
int		next_line_mini(int fd, t_data *data);
int		is_space(int c);
int		is_asset(char *input);
int		extract_data(t_data *data, char *input);
int		parsing(t_game *game, t_data *data, char *file);
int		save_map(t_data *data, char *input);
int		save_asset(t_data *data, char *input, int *i);

/*data_sort.c*/
int		sort_data(t_data *data);
int		transfer_dir(t_data *data, char *str, int i);
int		transfer_col(char *str, int *color, int j);

/*data_gnl.c*/
char	*get_next_line(int fd);
void	print_data(t_data *data);


#endif