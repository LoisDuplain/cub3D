/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_lr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:20:57 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/27 16:21:02 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player_lr(t_game *game, long delta, t_bool keyboard[384])
{
	t_vector3	dir;

	if (keyboard[KEY_A] || keyboard[KEY_D])
	{
		dir.vx = cos(game->cur_lvl->player.yaw) * MOVEMENT_SPEED * delta;
		dir.vy = sin(game->cur_lvl->player.yaw) * MOVEMENT_SPEED * delta;
		if (keyboard[KEY_A])
			move_player(game, -dir.vx, -dir.vy);
		if (keyboard[KEY_D])
			move_player(game, dir.vx, dir.vy);
	}
}
