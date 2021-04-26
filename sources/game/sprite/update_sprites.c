/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:17:13 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 19:51:56 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_sprites(t_game *game)
{
	t_sprite	*sprite;
	t_vector3	v;
	int			sprite_index;

	sprite_index = -1;
	while (++sprite_index < game->cur_lvl->sprites_count)
	{
		sprite = &game->cur_lvl->sprites[sprite_index];
		v = sub_vector_vector(sprite->position, game->cur_lvl->player.position);
		if (distance_square2(v.vx, v.vy) > game->cur_lvl->player.render_distance
			* game->cur_lvl->player.render_distance)
		{
			sprite->to_render = FALSE;
			continue ;
		}
		sprite->plane.px = v.vx;
		sprite->plane.py = v.vy;
		sprite->plane.dist = -v.vx * sprite->position.vx
			- v.vy * sprite->position.vy;
		sprite->to_render = TRUE;
	}
}
