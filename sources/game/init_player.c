/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:32:02 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/06 18:22:32 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	game->player = game->current_level->player;
	game->player.location.vx += 0.5;
	game->player.location.vy += 0.5;
	game->player.pitch = 0;
	game->player.fov_x = 120;
	game->player.fov_y = 90;
	dprintf(1, "Player{location: Vector3{vx: %f, vy: %f, vz: %f}, yaw: %f, pitch %f, fov_x: %d, fov_y: %d}\n", game->player.location.vx, game->player.location.vy, game->player.location.vz, game->player.yaw, game->player.pitch, game->player.fov_x, game->player.fov_y);
}
