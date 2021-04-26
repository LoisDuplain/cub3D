/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:32:02 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 19:51:25 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	game->cur_lvl->player = game->cur_lvl->player;
	game->cur_lvl->player.position.vx += 0.5;
	game->cur_lvl->player.position.vy += 0.5;
	game->cur_lvl->player.pitch = 0;
	game->cur_lvl->player.fov_x = 120;
	game->cur_lvl->player.fov_y = 90;
	game->cur_lvl->player.render_distance = 10;
}
