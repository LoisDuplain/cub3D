/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:34:52 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/27 16:35:14 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_loop(t_game *game, long delta, t_bool keyboard[384])
{
	if (keyboard[KEY_RIGHT] || keyboard[KEY_LEFT] || keyboard[KEY_UP] || keyboard[KEY_DOWN])
		rotate_camera(game, delta, keyboard);
	if (keyboard[KEY_W] || keyboard[KEY_S] || keyboard[KEY_A] || keyboard[KEY_D])
	{
		move_player_fb(game, delta, keyboard);
		move_player_lr(game, delta, keyboard);
		update_x_planes(game->cur_lvl);
		update_y_planes(game->cur_lvl);
		update_sprites(game);
	}
	if (keyboard[KEY_PLUS] || keyboard[KEY_MINUS])
		change_fov(game, delta, keyboard);
	if (keyboard[KEY_K] || keyboard[KEY_L])
		change_render_distance(game, delta, keyboard);
	change_level(game, keyboard);
}
