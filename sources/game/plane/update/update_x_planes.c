/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_x_planes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:30:32 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/21 12:21:37 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    update_x_planes(t_world *world)
{
	int		x_index;
	t_plane	*plane;
	int		render_distance;

	render_distance = world->player.render_distance;
	x_index = world->player.position.vx - render_distance - 3;
	while (++x_index < world->player.position.vx + render_distance)
	{
		if (x_index < 0 || x_index >= world->x_planes_size)
			continue ;
		plane = &world->x_planes[x_index];
		plane->px_dist = plane->dist - world->player.position.vx;
	}
}
