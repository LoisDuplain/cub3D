/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:32:02 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 18:41:02 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	game->current_level->player = game->current_level->player;
	game->current_level->player.position.vx += 0.5;
	game->current_level->player.position.vy += 0.5;
	game->current_level->player.pitch = 0;
	game->current_level->player.fov_x = 120;
	game->current_level->player.fov_y = 90;
	game->current_level->player.render_distance = 10;
}
