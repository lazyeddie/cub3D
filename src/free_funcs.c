/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <aapostol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:26:55 by aapostol          #+#    #+#             */
/*   Updated: 2023/12/06 16:13:35 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit (1);
}

void	free_game(t_game *game, char *msg)
{
	game->data = free_data(game->data);
	game->rays = free_ptr(game->rays);
	if (game->assets.north.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->assets.north.mlx_img);
	if (game->assets.south.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->assets.south.mlx_img);
	if (game->assets.west.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->assets.west.mlx_img);
	if (game->assets.east.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->assets.east.mlx_img);
	if (game->img)
		mlx_destroy_image(game->mlx_ptr, game->img);
	if (game->win.ptr)
		mlx_destroy_window(game->mlx_ptr, game->win.ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		game->mlx_ptr = free_ptr(game->mlx_ptr);
	}
	if (msg)
		ft_error(msg);
}

t_data	*free_data(t_data *data)
{
	int	i;

	i = -1;
	if (data->map)
		data->map = free_array(data->map);
	if (data->north)
		data->north = free_ptr(data->north);
	if (data->south)
		data->south = free_ptr(data->south);
	if (data->west)
		data->west = free_ptr(data->west);
	if (data->east)
		data->east = free_ptr(data->east);
	if (data->input)
		data->input = free_ptr(data->input);
	while (i++ < 6)
		data->assarr[i] = free_ptr(data->assarr[i]);
	data = NULL;
	return (NULL);
}

void	*free_array(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free_ptr(arr[i++]);
		arr = free_ptr(arr);
	}
	return (arr);
}

void	*free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
	return (ptr);
}
