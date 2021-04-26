/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_y_planes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:59:01 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 18:47:13 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_y_planes(t_level *level)
{
	int		y_index;
	t_plane	*plane;
	int		render_distance;

	render_distance = level->player.render_distance;
	y_index = level->player.position.vy - render_distance - 3;
	while (++y_index < level->player.position.vy + render_distance)
	{
		if (y_index < 0 || y_index >= level->y_planes_size)
			continue ;
		plane = &level->y_planes[y_index];
		plane->py_dist = plane->dist - level->player.position.vy;
	}
}
