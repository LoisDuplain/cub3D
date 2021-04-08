/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:34:52 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/08 16:50:33 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_loop(t_game *game, long delta, t_bool keyboard[384])
{
	(void)game;
	(void)delta;
	(void)keyboard;
	if (keyboard[KEY_RIGHT])
	{
		game->world.player.yaw += 5;
	}
	if (keyboard[KEY_LEFT])
	{
		game->world.player.yaw -= 5;
	}
}
