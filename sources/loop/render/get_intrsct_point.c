/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intrsct_point.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:42:38 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 16:15:26 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector3	get_intrsct_point(t_vector3 p_loc, t_vector3 r_dir, t_plane plane,
	float distance)
{
	t_vector3	intrsct;

	intrsct.vx = p_loc.vx + r_dir.vx * distance;
	intrsct.vy = p_loc.vy + r_dir.vy * distance;
	intrsct.vz = p_loc.vz + r_dir.vz * distance;
	if (plane.px == 1)
		if (ft_fabs(intrsct.vx - plane.dist) <= 0.1)
			intrsct.vx = plane.dist;
	if (plane.py == 1)
		if (ft_fabs(intrsct.vy - plane.dist) <= 0.1)
			intrsct.vy = plane.dist;
	return (intrsct);
}
