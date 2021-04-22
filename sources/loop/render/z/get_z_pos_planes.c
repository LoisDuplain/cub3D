/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_z_pos_planes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:08:07 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/22 19:14:49 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_z_pos_planes(t_raycast_result *r_result, t_world world)
{
	float	distance;
	t_plane	plane;

	plane = world.z_planes[1];
	distance = plane.pz_dist / r_result->ray.r_dir.vz;
	if (distance < 0 || distance > r_result->distance
		|| distance > world.player.render_distance)
		return ;
	r_result->distance = distance;
	r_result->plane = plane;
	r_result->intrsct = get_wall_intrsct_point(r_result->p_loc, r_result->ray.r_dir,
			r_result->plane, distance);
}
