/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:32:02 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/08 16:19:35 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	game->world.player = game->current_level->player;
	game->world.player.location.vx += 0.5;
	game->world.player.location.vy += 0.5;
	game->world.player.pitch = 0;
	game->world.player.fov_x = 120;
	game->world.player.fov_y = 90;
	dprintf(1, "Player{location: Vector3{vx: %f, vy: %f, vz: %f}, yaw: %f, pitch %f, fov_x: %d, fov_y: %d}\n", game->world.player.location.vx, game->world.player.location.vy, game->world.player.location.vz, game->world.player.yaw, game->world.player.pitch, game->world.player.fov_x, game->world.player.fov_y);
}
