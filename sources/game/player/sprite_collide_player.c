/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_collide_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:21:30 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/27 16:42:38 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	sprite_collide_player(t_game *game, float nx, float ny)
{
	float		dist;
	int			sprite_index;
	t_sprite	sprite;

	sprite_index = 0;
	while (++sprite_index < game->cur_lvl->sprites_count)
	{
		sprite = game->cur_lvl->sprites[sprite_index];
		dist = distance_square2(sprite.position.vx - nx,
				sprite.position.vy - ny);
		if (dist <= 0.0625)
			return (TRUE);
	}
	return (FALSE);
}
