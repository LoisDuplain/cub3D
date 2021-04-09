/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:34:52 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/09 14:45:47 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_loop(t_game *game, long delta, t_bool keyboard[384])
{
	(void)game;
	(void)delta;
	(void)keyboard;
	if (keyboard[KEY_RIGHT])
		game->world.player.yaw += 5;
	if (keyboard[KEY_LEFT])
		game->world.player.yaw -= 5;
	if (keyboard[KEY_W])
		game->world.player.location.vy -= 0.1;
	if (keyboard[KEY_S])
		game->world.player.location.vy += 0.1;
	if (keyboard[KEY_A])
		game->world.player.location.vx -= 0.1;
	if (keyboard[KEY_D])
		game->world.player.location.vx += 0.1;
}
