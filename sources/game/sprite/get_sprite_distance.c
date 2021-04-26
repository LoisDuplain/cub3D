/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_distance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:11:45 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 16:11:56 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_sprite_distance(t_sprite sprite, t_ray ray, t_player player)
{
	float	div;

	div = sprite.plane.px * ray.r_dir.vx + sprite.plane.py * ray.r_dir.vy;
	if (div == 0)
		return (0);
	return ((-sprite.plane.px * player.position.vx
			- sprite.plane.py * player.position.vy
			- sprite.plane.dist) / div);
}
