/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_current_level.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:31:37 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 19:51:25 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_current_level(t_game *game)
{
	init_textures(game);
	init_player(game);
	init_rays(game);
	init_planes(game);
	update_rays(game);
	update_x_planes(game->cur_lvl);
	update_y_planes(game->cur_lvl);
	update_z_planes(game->cur_lvl);
	update_sprites(game);
}
