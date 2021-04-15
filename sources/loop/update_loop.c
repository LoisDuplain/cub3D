/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:34:52 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/15 20:02:34 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_loop(t_game *game, long delta, t_bool keyboard[384])
{
	if (keyboard[KEY_RIGHT] || keyboard[KEY_LEFT] || keyboard[KEY_UP] || keyboard[KEY_DOWN])
	{
		if (keyboard[KEY_RIGHT])
			game->world.player.yaw += ROTATION_SPEED * delta;
		if (keyboard[KEY_LEFT])
			game->world.player.yaw -= ROTATION_SPEED * delta;
		if (keyboard[KEY_UP] || keyboard[KEY_DOWN]) {
			if (keyboard[KEY_UP])
				game->world.player.pitch -= ROTATION_SPEED * delta;
			if (keyboard[KEY_DOWN])
				game->world.player.pitch += ROTATION_SPEED * delta;
			if (game->world.player.pitch < -M_PI / 2)
				game->world.player.pitch = -M_PI / 2;
			if (game->world.player.pitch > M_PI / 2)
				game->world.player.pitch = M_PI / 2;
		}
		update_rays(game);
	}
	if (keyboard[KEY_W] || keyboard[KEY_S] || keyboard[KEY_A] || keyboard[KEY_D])
	{
		if (keyboard[KEY_W] || keyboard[KEY_S])
		{
			if (keyboard[KEY_W])
				game->world.player.location.vy -= MOVEMENT_SPEED * delta;
			if (keyboard[KEY_S])
				game->world.player.location.vy += MOVEMENT_SPEED * delta;
			update_y_planes(&game->world);
		}
		if (keyboard[KEY_A] || keyboard[KEY_D])
		{
			if (keyboard[KEY_A])
				game->world.player.location.vx -= MOVEMENT_SPEED * delta;
			if (keyboard[KEY_D])
				game->world.player.location.vx += MOVEMENT_SPEED * delta;
			update_x_planes(&game->world);
		}
	}
}
