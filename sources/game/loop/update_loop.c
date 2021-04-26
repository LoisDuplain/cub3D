/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:34:52 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 18:46:56 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_loop(t_game *game, long delta, t_bool keyboard[384])
{
	if (keyboard[KEY_RIGHT] || keyboard[KEY_LEFT] || keyboard[KEY_UP] || keyboard[KEY_DOWN])
	{
		if (keyboard[KEY_RIGHT])
			game->current_level->player.yaw += ROTATION_SPEED * delta;
		if (keyboard[KEY_LEFT])
			game->current_level->player.yaw -= ROTATION_SPEED * delta;
		if (keyboard[KEY_UP] || keyboard[KEY_DOWN]) {
			if (keyboard[KEY_UP])
				game->current_level->player.pitch -= ROTATION_SPEED * delta;
			if (keyboard[KEY_DOWN])
				game->current_level->player.pitch += ROTATION_SPEED * delta;
			if (game->current_level->player.pitch < -M_PI / 2)
				game->current_level->player.pitch = -M_PI / 2;
			if (game->current_level->player.pitch > M_PI / 2)
				game->current_level->player.pitch = M_PI / 2;
		}
		update_rays(game);
	}
	if (keyboard[KEY_W] || keyboard[KEY_S] || keyboard[KEY_A] || keyboard[KEY_D])
	{
		if (keyboard[KEY_W] || keyboard[KEY_S])
		{
			if (keyboard[KEY_W])
				game->current_level->player.position.vy -= MOVEMENT_SPEED * delta;
			if (keyboard[KEY_S])
				game->current_level->player.position.vy += MOVEMENT_SPEED * delta;
			update_y_planes(game->current_level);
		}
		if (keyboard[KEY_A] || keyboard[KEY_D])
		{
			if (keyboard[KEY_A])
				game->current_level->player.position.vx -= MOVEMENT_SPEED * delta;
			if (keyboard[KEY_D])
				game->current_level->player.position.vx += MOVEMENT_SPEED * delta;
			update_x_planes(game->current_level);
		}
		update_sprites(game);
	}
	if (keyboard[KEY_PLUS] || keyboard[KEY_MINUS])
	{
		if (keyboard[KEY_PLUS])
		{
			game->current_level->player.fov_x += 0.12 * delta;
			if (game->current_level->player.fov_x > 179)
				game->current_level->player.fov_x = 179;
			game->current_level->player.fov_y = 9 * game->current_level->player.fov_x / 12;
		}
		if (keyboard[KEY_MINUS])
		{
			game->current_level->player.fov_x -= 0.12 * delta;
			if (game->current_level->player.fov_x < 1)
				game->current_level->player.fov_x = 1;
			game->current_level->player.fov_y = 9 * game->current_level->player.fov_x / 12;
		}
		init_rays(game);
		update_rays(game);
	}
	if (keyboard[KEY_K] || keyboard[KEY_L])
	{
		if (keyboard[KEY_K])
			game->current_level->player.render_distance -= 0.01 * delta;
		if (keyboard[KEY_L])
			game->current_level->player.render_distance += 0.01 * delta;
		if (game->current_level->player.render_distance < 0.7)
			game->current_level->player.render_distance = 0.7;
		if (game->current_level->player.render_distance > 5000)
			game->current_level->player.render_distance = 5000;
		update_x_planes(game->current_level);
		update_y_planes(game->current_level);
		update_z_planes(game->current_level);
	}
	if (keyboard[47])
	{
		next_level(game);
	}
}
