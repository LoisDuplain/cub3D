/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:34:52 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/21 14:53:11 by lduplain         ###   ########lyon.fr   */
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
				game->world.player.position.vy -= MOVEMENT_SPEED * delta;
			if (keyboard[KEY_S])
				game->world.player.position.vy += MOVEMENT_SPEED * delta;
			update_y_planes(&game->world);
		}
		if (keyboard[KEY_A] || keyboard[KEY_D])
		{
			if (keyboard[KEY_A])
				game->world.player.position.vx -= MOVEMENT_SPEED * delta;
			if (keyboard[KEY_D])
				game->world.player.position.vx += MOVEMENT_SPEED * delta;
			update_x_planes(&game->world);
		}
		update_sprites(game);
		puts("----------------------------------------------------------");
		int i = -1;
		while (++i < game->current_level->sprites_count)
		{
			t_sprite sprite = game->current_level->sprites[i];
			dprintf(1, "Sprite: {(t_plane)plane:{%f, %f, %f, %f}, (t_vector3)position{%f, %f, %f}}\n", sprite.plane.px, sprite.plane.py, sprite.plane.pz, sprite.plane.dist, sprite.position.vx, sprite.position.vy, sprite.position.vz);
		}
		puts("----------------------------------------------------------");
	}
	if (keyboard[KEY_PLUS] || keyboard[KEY_MINUS])
	{
		if (keyboard[KEY_PLUS])
		{
			game->world.player.fov_x += 0.12 * delta;
			if (game->world.player.fov_x > 179)
				game->world.player.fov_x = 179;
			game->world.player.fov_y = 9 * game->world.player.fov_x / 12;
		}
		if (keyboard[KEY_MINUS])
		{
			game->world.player.fov_x -= 0.12 * delta;
			if (game->world.player.fov_x < 1)
				game->world.player.fov_x = 1;
			game->world.player.fov_y = 9 * game->world.player.fov_x / 12;
		}
		init_rays(game);
		update_rays(game);
	}
	if (keyboard[KEY_K] || keyboard[KEY_L])
	{
		if (keyboard[KEY_K])
			game->world.player.render_distance -= 0.01 * delta;
		if (keyboard[KEY_L])
			game->world.player.render_distance += 0.01 * delta;
		if (game->world.player.render_distance < 0.7)
			game->world.player.render_distance = 0.7;
		if (game->world.player.render_distance > 5000)
			game->world.player.render_distance = 5000;
		update_x_planes(&game->world);
		update_y_planes(&game->world);
		update_z_planes(&game->world);
	}
}
