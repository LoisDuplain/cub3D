/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intrsct_y_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:42:36 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 16:12:44 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	intrsct_y_plane(t_raycast_result *r_result, t_world world,
	char **map_content, t_plane plane)
{
	float		distance;
	t_vector3	intrsct;
	int			sub;

	distance = -(r_result->p_loc.vy - plane.dist) / r_result->r_dir.vy;
	if (distance < 0)
		return (FALSE);
	if (distance > r_result->distance || distance > RENDER_DISTANCE)
		return (TRUE);
	intrsct = get_intrsct_point(r_result->p_loc, r_result->r_dir,
			plane, distance);
	if (intrsct.vz <= 0 || intrsct.vz >= 1)
		return (TRUE);
	sub = 0;
	if (r_result->r_dir.vy < 0)
		sub = 1;
	if (is_in_world(intrsct, world)
		&& map_content[(int)intrsct.vy - sub][(int)intrsct.vx] == 1)
	{
		r_result->distance = distance;
		r_result->color = create_color(0, 0, 0, 255);
		return (TRUE);
	}
	return (FALSE);
}
