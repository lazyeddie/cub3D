/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:36:52 by aapostol          #+#    #+#             */
/*   Updated: 2023/12/06 11:56:02 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>
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
	INVALID_MAP_ERR0,
	INVALID_MAP_ERR1,
	INVALID_MAP_ERR2,
}	t_ret;

/*data_map_check.c*/
int		lonely_space(char *map);
int		check_walls(char **map, int x, int y, int ymax);
int		map_check_quali(t_data *data, char **map);
void	map_size(t_data *data, int x, int y);

/*data_check.c*/
void	skip_word(char *str, int *i, bool word);
int		check_counter(int *count);
int		check_asset(t_data *data, char *input, int *i);
int		check_map(char c, char c1, int *count);
int		check_data(t_data *data, char *input);

/*data_create.c*/
int		next_line_mini(int fd, t_data *data);
int		extract_data(t_data *data, char *input);
int		save_asset(t_data *data, char *input, int *i);
char	*ft_strerror(int ret);
int		parsing(t_game *game, t_data *data, char *file);

/*data_sort.c*/
int		sort_data(t_data *data);
int		transfer_dir(t_data *data, char *str, int i);
int		transfer_col(char *str, int *color, int j);
int		transfer_assets(t_data *data);

/*data_utils.c*/
void	skip_a(char *str, int *i, int a);
int		ft_arrlen(char **arr);
int		is_wall(int c);
int		is_abyss(int c);
int		check_number(char *str);

/*data_utils2.c*/
int		is_space(int c);
int		is_asset(char *input);
int		not_valid_file(char *s1, char *s2, int n);
char	*ft_strnjoin(char const *s1, char const *s2, int len);

#endif