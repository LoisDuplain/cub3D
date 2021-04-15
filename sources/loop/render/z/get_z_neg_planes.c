/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_z_neg_planes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:08:44 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/15 16:07:12 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_z_neg_planes(t_raycast_result *r_result, t_world world)
{
	float	distance;
	t_plane	plane;

	plane = world.z_planes[0];
	distance = -r_result->p_loc.vz / r_result->ray.r_direction.vz;
	if (distance < 0 || distance > r_result->distance
		|| distance > RENDER_DISTANCE)
		return ;
	r_result->distance = distance;
	r_result->plane = plane;
	r_result->intrsct = get_intrsct_point(r_result->p_loc, r_result->ray.r_direction,
			r_result->plane, distance);
}
