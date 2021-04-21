/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:17:13 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/21 16:34:59 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_sprites(t_game *game)
{
	t_sprite	*sprite;
	t_vector3	v;
	int			sprite_index;

	sprite_index = -1;
	while (++sprite_index < game->current_level->sprites_count)
	{
		sprite = &game->current_level->sprites[sprite_index];
		v = sub_vector_vector(sprite->position, game->world.player.position);
		sprite->plane.px = v.vx;
		sprite->plane.py = v.vy;
		sprite->plane.pz = 0;
		sprite->plane.dist = -v.vx * sprite->position.vx - v.vy * sprite->position.vy;
	}
}
