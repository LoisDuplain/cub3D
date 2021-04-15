/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_x_planes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:30:32 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/15 20:00:50 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    update_x_planes(t_world *world)
{
	int		x_index;
	t_plane	*plane;

	x_index = world->player.location.vx - RENDER_DISTANCE - 2;
	while (++x_index < world->player.location.vx + RENDER_DISTANCE - 1)
	{
		if (x_index < 0 || x_index >= world->x_planes_size)
			continue ;
		plane = &world->x_planes[x_index];
		plane->px_dist = plane->dist - world->player.location.vx;
	}
}
