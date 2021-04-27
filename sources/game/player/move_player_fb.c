/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_fb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:19:17 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/27 16:19:48 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player_fb(t_game *game, long delta, t_bool keyboard[384])
{
	t_vector3	dir;

	if (keyboard[KEY_W] || keyboard[KEY_S])
	{
		dir.vx = -sin(game->cur_lvl->player.yaw) * MOVEMENT_SPEED * delta;
		dir.vy = cos(game->cur_lvl->player.yaw) * MOVEMENT_SPEED * delta;
		if (keyboard[KEY_W])
			move_player(game, -dir.vx, -dir.vy);
		if (keyboard[KEY_S])
			move_player(game, dir.vx, dir.vy);
	}
}
