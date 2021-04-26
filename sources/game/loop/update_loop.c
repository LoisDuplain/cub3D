/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:34:52 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 19:51:25 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_loop(t_game *game, long delta, t_bool keyboard[384])
{
	if (keyboard[KEY_RIGHT] || keyboard[KEY_LEFT] || keyboard[KEY_UP] || keyboard[KEY_DOWN])
	{
		if (keyboard[KEY_RIGHT])
			game->cur_lvl->player.yaw += ROTATION_SPEED * delta;
		if (keyboard[KEY_LEFT])
			game->cur_lvl->player.yaw -= ROTATION_SPEED * delta;
		if (keyboard[KEY_UP] || keyboard[KEY_DOWN]) {
			if (keyboard[KEY_UP])
				game->cur_lvl->player.pitch -= ROTATION_SPEED * delta;
			if (keyboard[KEY_DOWN])
				game->cur_lvl->player.pitch += ROTATION_SPEED * delta;
			if (game->cur_lvl->player.pitch < -M_PI / 2)
				game->cur_lvl->player.pitch = -M_PI / 2;
			if (game->cur_lvl->player.pitch > M_PI / 2)
				game->cur_lvl->player.pitch = M_PI / 2;
		}
		update_rays(game);
	}
	if (keyboard[KEY_W] || keyboard[KEY_S] || keyboard[KEY_A] || keyboard[KEY_D])
	{
		if (keyboard[KEY_W] || keyboard[KEY_S])
		{
			if (keyboard[KEY_W])
				game->cur_lvl->player.position.vy -= MOVEMENT_SPEED * delta;
			if (keyboard[KEY_S])
				game->cur_lvl->player.position.vy += MOVEMENT_SPEED * delta;
			update_y_planes(game->cur_lvl);
		}
		if (keyboard[KEY_A] || keyboard[KEY_D])
		{
			if (keyboard[KEY_A])
				game->cur_lvl->player.position.vx -= MOVEMENT_SPEED * delta;
			if (keyboard[KEY_D])
				game->cur_lvl->player.position.vx += MOVEMENT_SPEED * delta;
			update_x_planes(game->cur_lvl);
		}
		update_sprites(game);
	}
	if (keyboard[KEY_PLUS] || keyboard[KEY_MINUS])
	{
		if (keyboard[KEY_PLUS])
		{
			game->cur_lvl->player.fov_x += 0.12 * delta;
			if (game->cur_lvl->player.fov_x > 179)
				game->cur_lvl->player.fov_x = 179;
			game->cur_lvl->player.fov_y = 9 * game->cur_lvl->player.fov_x / 12;
		}
		if (keyboard[KEY_MINUS])
		{
			game->cur_lvl->player.fov_x -= 0.12 * delta;
			if (game->cur_lvl->player.fov_x < 1)
				game->cur_lvl->player.fov_x = 1;
			game->cur_lvl->player.fov_y = 9 * game->cur_lvl->player.fov_x / 12;
		}
		init_rays(game);
		update_rays(game);
	}
	if (keyboard[KEY_K] || keyboard[KEY_L])
	{
		if (keyboard[KEY_K])
			game->cur_lvl->player.render_distance -= 0.01 * delta;
		if (keyboard[KEY_L])
			game->cur_lvl->player.render_distance += 0.01 * delta;
		if (game->cur_lvl->player.render_distance < 0.7)
			game->cur_lvl->player.render_distance = 0.7;
		if (game->cur_lvl->player.render_distance > 5000)
			game->cur_lvl->player.render_distance = 5000;
		update_x_planes(game->cur_lvl);
		update_y_planes(game->cur_lvl);
		update_z_planes(game->cur_lvl);
	}
	if (keyboard[KEY_GREATER])
		next_level(game);
	if (keyboard[KEY_LESS])
		previous_level(game);
}
