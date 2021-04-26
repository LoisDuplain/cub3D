/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_y_pos_planes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:06:07 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 18:39:25 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_y_pos_planes(t_raycast_result *r_result, t_level *level)
{
	int			y_index;
	t_plane		plane;
	t_bool		intrsct;

	y_index = (int)r_result->p_loc.vy - 1;
	while (++y_index < level->y_planes_size
		&& y_index < r_result->p_loc.vy + level->player.render_distance - 1)
	{
		plane = level->y_planes[y_index];
		intrsct = intrsct_y_plane(r_result, level, plane);
		if (!intrsct)
			continue ;
		break ;
	}
}
