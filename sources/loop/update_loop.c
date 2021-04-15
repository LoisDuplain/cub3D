/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:34:52 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/15 16:40:17 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_loop(t_game *game, long delta, t_bool keyboard[384])
{
	(void)delta;
	if (keyboard[KEY_RIGHT] || keyboard[KEY_LEFT] || keyboard[KEY_UP] || keyboard[KEY_DOWN])
	{
		if (keyboard[KEY_RIGHT])
			game->world.player.yaw += ROTATION_SPEED * delta;
		if (keyboard[KEY_LEFT])
			game->world.player.yaw -= ROTATION_SPEED * delta;
		if (keyboard[KEY_UP])
			game->world.player.pitch -= ROTATION_SPEED * delta;
		if (keyboard[KEY_DOWN])
			game->world.player.pitch += ROTATION_SPEED * delta;
		update_rays(game);
	}
	if (keyboard[KEY_W])
		game->world.player.location.vy -= MOVEMENT_SPEED * delta;
	if (keyboard[KEY_S])
		game->world.player.location.vy += MOVEMENT_SPEED * delta;
	if (keyboard[KEY_A])
		game->world.player.location.vx -= MOVEMENT_SPEED * delta;
	if (keyboard[KEY_D])
		game->world.player.location.vx += MOVEMENT_SPEED * delta;
}
