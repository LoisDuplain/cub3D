/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_z_neg_planes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:08:44 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 18:40:09 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_z_neg_planes(t_raycast_result *r_result, t_level *level)
{
	float	distance;
	t_plane	plane;

	plane = level->z_planes[0];
	distance = plane.pz_dist / r_result->ray.r_dir.vz;
	if (distance < 0 || distance > r_result->distance
		|| distance > level->player.render_distance)
		return ;
	r_result->distance = distance;
	r_result->plane = plane;
	r_result->intrsct = get_plane_intrsct_point(r_result->p_loc,
			r_result->ray.r_dir, r_result->plane, distance);
}
