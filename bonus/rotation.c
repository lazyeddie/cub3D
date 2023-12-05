/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <aapostol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:34:09 by aapostol          #+#    #+#             */
/*   Updated: 2023/12/05 20:38:06 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_player *player)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(-ROTATION_SPEED) - \
					player->dir_y * sin(-ROTATION_SPEED);
	player->dir_y = old_dir_x * sin(-ROTATION_SPEED) + \
					player->dir_y * cos(-ROTATION_SPEED);
	player->plane_x = player->plane_x * cos(-ROTATION_SPEED) - \
					player->plane_y * sin(-ROTATION_SPEED);
	player->plane_y = old_plane_x * sin(-ROTATION_SPEED) + \
					player->plane_y * cos(-ROTATION_SPEED);
}

void	rotate_right(t_player *player)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(ROTATION_SPEED) - \
					player->dir_y * sin(ROTATION_SPEED);
	player->dir_y = old_dir_x * sin(ROTATION_SPEED) + \
					player->dir_y * cos(ROTATION_SPEED);
	player->plane_x = player->plane_x * cos(ROTATION_SPEED) - \
					player->plane_y * sin(ROTATION_SPEED);
	player->plane_y = old_plane_x * sin(ROTATION_SPEED) + \
					player->plane_y * cos(ROTATION_SPEED);
}
