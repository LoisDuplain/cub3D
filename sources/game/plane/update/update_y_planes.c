/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_y_planes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:59:01 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/15 19:59:07 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    update_y_planes(t_world *world)
{
	int		y_index;
	t_plane	*plane;

	y_index = world->player.location.vy - RENDER_DISTANCE - 2;
	while (++y_index < world->player.location.vy + RENDER_DISTANCE - 1)
	{
		if (y_index < 0 || y_index >= world->y_planes_size)
			continue ;
		plane = &world->y_planes[y_index];
		plane->py_dist = plane->dist - world->player.location.vy;
	}
}
