/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_intrsct_point.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:17:39 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 16:17:50 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector3	get_sprite_intrsct_point(t_player player, t_ray ray, float distance)
{
	t_vector3	intrsct;

	intrsct.vx = player.position.vx + ray.r_dir.vx * distance;
	intrsct.vy = player.position.vy + ray.r_dir.vy * distance;
	intrsct.vz = player.position.vz + ray.r_dir.vz * distance;
	return (intrsct);
}
