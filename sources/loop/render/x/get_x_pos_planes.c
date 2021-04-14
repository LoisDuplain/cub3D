/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_x_pos_planes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:51:46 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 16:15:00 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_x_pos_planes(t_raycast_result *r_result, t_world world,
	char **map_content)
{
	int			x_index;
	t_plane		plane;
	t_bool		intrsct;

	x_index = (int)r_result->p_loc.vx - 1;
	while (++x_index < world.x_planes_size
		&& x_index < r_result->p_loc.vx + RENDER_DISTANCE - 1)
	{
		plane = world.x_planes[x_index];
		intrsct = intrsct_x_plane(r_result, world, map_content, plane);
		if (!intrsct)
			continue ;
		break ;
	}
}