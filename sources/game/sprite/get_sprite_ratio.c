/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_ratio.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:19:24 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 16:19:41 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_sprite_ratio(t_vector3 intrsct, t_sprite sprite, t_player player)
{
	t_vector3	v2;
	t_vector3	u;

	u.vx = intrsct.vx - sprite.position.vx;
	u.vy = intrsct.vy - sprite.position.vy;
	v2 = normalize_vector(
			create_vector(
				sprite.position.vy - player.position.vy,
				player.position.vx - sprite.position.vx,
				0
				)
			);
	return ((u.vx * v2.vx) + (u.vy * v2.vy) + 0.5);
}
