/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_planes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:42:08 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/27 14:42:24 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_planes(t_render_thread *r_thread, t_ray ray,
	t_raycast_result *r_result)
{
	if (ray.r_dir.vx > 0)
		get_x_pos_planes(r_result, r_thread->lvl);
	else
		get_x_neg_planes(r_result, r_thread->lvl);
	if (ray.r_dir.vy > 0)
		get_y_pos_planes(r_result, r_thread->lvl);
	else
		get_y_neg_planes(r_result, r_thread->lvl);
	if (r_result->distance == INT_MAX)
	{
		if (ray.r_dir.vz > 0)
			get_z_pos_planes(r_result, r_thread->lvl);
		else
			get_z_neg_planes(r_result, r_thread->lvl);
	}
}
