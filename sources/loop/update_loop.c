/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:34:52 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/13 14:08:02 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_loop(t_game *game, long delta, t_bool keyboard[384])
{
	(void)delta;
	if (keyboard[KEY_RIGHT])
	{
		game->world.player.yaw += 0.01;
		int i = -1;
		while (++i < game->rays_size)
		{
			t_vector3	v;
			float		cccooosss = cos(0.1);
			float		sssiiinnn = sin(0.1);
			v.vx = cccooosss * game->rays[i].direction.vx - sssiiinnn * game->rays[i].direction.vy;
			v.vy = sssiiinnn * game->rays[i].direction.vx + cccooosss * game->rays[i].direction.vy;
			v.vz = game->rays[i].direction.vz;
			game->rays[i].direction = v;
		}
		game->world.player.yaw += 0.01;
	}
	if (keyboard[KEY_LEFT])
	{
		int i = -1;
		while (++i < game->rays_size)
		{
			t_vector3	v;
			float		cccooosss = cos(-0.1);
			float		sssiiinnn = sin(-0.1);
			v.vx = cccooosss * game->rays[i].direction.vx - sssiiinnn * game->rays[i].direction.vy;
			v.vy = sssiiinnn * game->rays[i].direction.vx + cccooosss * game->rays[i].direction.vy;
			v.vz = game->rays[i].direction.vz;
			game->rays[i].direction = v;
		}
		game->world.player.yaw -= 0.01;
	}
	if (keyboard[KEY_W])
		game->world.player.location.vy -= 0.1;
	if (keyboard[KEY_S])
		game->world.player.location.vy += 0.1;
	if (keyboard[KEY_A])
		game->world.player.location.vx -= 0.1;
	if (keyboard[KEY_D])
		game->world.player.location.vx += 0.1;
}
