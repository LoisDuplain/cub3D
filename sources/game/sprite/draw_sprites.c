/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:39:59 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 19:51:23 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprites(t_render_thread *r_thread, t_raycast_result *r_result,
	t_ray ray)
{
	t_game		*game;
	int			sprite_index;
	t_sprite	sprite;

	game = r_thread->game;
	sprite_index = -1;
	while (++sprite_index < game->cur_lvl->sprites_count)
	{
		sprite = game->cur_lvl->sprites[sprite_index];
		if (!sprite.to_render)
			continue ;
		draw_sprite(r_thread, r_result, ray, sprite);
	}
}
