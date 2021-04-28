/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:12:20 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/28 17:24:20 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_fov(t_game *game, t_bool keyboard[384])
{
	if (keyboard[KEY_PLUS])
	{
		game->cur_lvl->player.fov_x += 2;
		if (game->cur_lvl->player.fov_x > 168)
			game->cur_lvl->player.fov_x = 168;
	}
	if (keyboard[KEY_MINUS])
	{
		game->cur_lvl->player.fov_x -= 2;
		if (game->cur_lvl->player.fov_x < 2)
			game->cur_lvl->player.fov_x = 2;
	}
	game->cur_lvl->player.fov_y = 9 * game->cur_lvl->player.fov_x / 12;
	init_rays(game);
	update_rays(game);
}
