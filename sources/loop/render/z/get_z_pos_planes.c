/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_z_pos_planes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:08:07 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 16:35:36 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_z_pos_planes(t_raycast_result *r_result, t_plane plane)
{
	float	distance;

	distance = -(r_result->p_loc.vz - 1) / r_result->r_dir.vz;
	if (distance < 0 || distance > r_result->distance
		|| distance > RENDER_DISTANCE)
		return ;
	r_result->distance = distance;
	r_result->plane = plane;
	r_result->intrsct = get_intrsct_point(r_result->p_loc, r_result->r_dir,
			plane, distance);
}
