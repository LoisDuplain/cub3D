/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_z_neg_planes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:08:44 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/16 10:53:34 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_z_neg_planes(t_raycast_result *r_result, t_world world)
{
	float	distance;
	t_plane	plane;

	plane = world.z_planes[0];
	distance = plane.pz_dist / r_result->ray.r_dir.vz;
	if (distance < 0 || distance > r_result->distance
		|| distance > world.player.render_distance)
		return ;
	r_result->distance = distance;
	r_result->plane = plane;
	r_result->intrsct = get_intrsct_point(r_result->p_loc, r_result->ray.r_dir,
			r_result->plane, distance);
}
