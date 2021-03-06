/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:46:05 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/28 12:47:28 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_camera(t_game *game, float ayaw, float apitch)
{
	game->cur_lvl->player.yaw += ayaw;
	game->cur_lvl->player.pitch += apitch;
	if (game->cur_lvl->player.pitch < -M_PI / 2)
		game->cur_lvl->player.pitch = -M_PI / 2;
	if (game->cur_lvl->player.pitch > M_PI / 2)
		game->cur_lvl->player.pitch = M_PI / 2;
	update_rays(game);
}
