/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:32:02 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/21 12:21:34 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	game->world.player = game->current_level->player;
	game->world.player.position.vx += 0.5;
	game->world.player.position.vy += 0.5;
	game->world.player.pitch = 0;
	game->world.player.fov_x = 120;
	game->world.player.fov_y = 90;
	game->world.player.render_distance = 10;
}
