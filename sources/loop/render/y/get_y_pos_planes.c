/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_y_pos_planes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:06:07 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 16:12:08 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_y_pos_planes(t_raycast_result *r_result, t_world world,
	char **map_content)
{
	int			y_index;
	t_plane		plane;
	t_bool		intrsct;

	y_index = (int)r_result->p_loc.vy - 1;
	while (++y_index < world.y_planes_size
		&& y_index < r_result->p_loc.vy + RENDER_DISTANCE - 1)
	{
		plane = world.y_planes[y_index];
		intrsct = intrsct_y_plane(r_result, world, map_content, plane);
		if (!intrsct)
			continue ;
		break ;
	}
}
