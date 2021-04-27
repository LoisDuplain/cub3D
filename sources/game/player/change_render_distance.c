/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_render_distance.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:13:13 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/27 16:13:22 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_render_distance(t_game *game, long delta, t_bool keyboard[384])
{
	if (keyboard[KEY_K])
	{
		game->cur_lvl->player.render_distance -= 0.01 * delta;
		if (game->cur_lvl->player.render_distance < 0.7)
			game->cur_lvl->player.render_distance = 0.7;
	}
	if (keyboard[KEY_L])
	{
		game->cur_lvl->player.render_distance += 0.01 * delta;
		if (game->cur_lvl->player.render_distance > 5000)
			game->cur_lvl->player.render_distance = 5000;
	}
	update_x_planes(game->cur_lvl);
	update_y_planes(game->cur_lvl);
	update_z_planes(game->cur_lvl);
}
