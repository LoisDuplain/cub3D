/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:11:36 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/27 16:11:47 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_camera(t_game *game, long delta, t_bool keyboard[384])
{
	if (keyboard[KEY_RIGHT])
		game->cur_lvl->player.yaw += ROTATION_SPEED * delta;
	if (keyboard[KEY_LEFT])
		game->cur_lvl->player.yaw -= ROTATION_SPEED * delta;
	if (keyboard[KEY_UP])
	{
		game->cur_lvl->player.pitch -= ROTATION_SPEED * delta;
		if (game->cur_lvl->player.pitch < -M_PI / 2)
			game->cur_lvl->player.pitch = -M_PI / 2;
	}
	if (keyboard[KEY_DOWN])
	{
		game->cur_lvl->player.pitch += ROTATION_SPEED * delta;
		if (game->cur_lvl->player.pitch > M_PI / 2)
			game->cur_lvl->player.pitch = M_PI / 2;
	}
	update_rays(game);
}
