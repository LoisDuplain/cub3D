/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intrsct_x_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:50:48 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/05 12:12:37 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	intrsct_x_plane(t_raycast_result *r_result, t_level *level,
	t_plane plane)
{
	float		dist;
	t_vector3	intrsct;
	int			sub;

	dist = plane.px_dist / r_result->ray.r_dir.vx;
	if (dist < 0)
		return (FALSE);
	if (dist > r_result->distance || dist > level->player.render_distance)
		return (TRUE);
	intrsct = get_plane_intrsct_point(r_result->p_loc, r_result->ray.r_dir,
			plane, dist);
	if (intrsct.vz <= 0 || intrsct.vz >= 1)
		return (TRUE);
	sub = 0;
	if (r_result->ray.r_dir.vx < 0)
		sub = 1;
	if (is_in_world(level, intrsct)
		&& level->map_content[(int)intrsct.vy][(int)intrsct.vx - sub] == 1)
	{
		r_result->distance = dist;
		r_result->plane = plane;
		r_result->intrsct = intrsct;
		return (TRUE);
	}
	return (FALSE);
}
