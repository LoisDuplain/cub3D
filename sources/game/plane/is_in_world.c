/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:41:31 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 16:54:13 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	is_in_world(t_world world, t_vector3 intrsct)
{
	float	vx;
	float	vy;
	float	vz;

	vx = intrsct.vx;
	if (vx < 0 || vx > world.x_planes_size)
		return (FALSE);
	vy = intrsct.vy;
	if (vy < 0 || vy > world.y_planes_size)
		return (FALSE);
	vz = intrsct.vz;
	if (vz < 0 || vz > 1)
		return (FALSE);
	return (TRUE);
}
