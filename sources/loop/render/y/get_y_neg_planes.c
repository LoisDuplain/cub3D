/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_y_neg_planes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:07:00 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 16:11:59 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_y_neg_planes(t_raycast_result *r_result, t_world world,
	char **map_content)
{
	int			y_index;
	t_plane		plane;
	t_bool		intrsct;

	y_index = (int)r_result->p_loc.vy + 1;
	while (--y_index >= 0
		&& y_index >= r_result->p_loc.vy - RENDER_DISTANCE - 1)
	{
		plane = world.y_planes[y_index];
		intrsct = intrsct_y_plane(r_result, world, map_content, plane);
		if (!intrsct)
			continue ;
		break ;
	}
}
