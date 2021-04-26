/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_x_planes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:30:32 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 18:45:05 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_x_planes(t_level *level)
{
	int		x_index;
	t_plane	*plane;
	int		render_distance;

	render_distance = level->player.render_distance;
	x_index = level->player.position.vx - render_distance - 3;
	while (++x_index < level->player.position.vx + render_distance)
	{
		if (x_index < 0 || x_index >= level->x_planes_size)
			continue ;
		plane = &level->x_planes[x_index];
		plane->px_dist = plane->dist - level->player.position.vx;
	}
}
