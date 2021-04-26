/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:35:42 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 18:46:08 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*render_loop(void *nr_thread)
{
	int					ray_index;
	t_ray				ray;
	t_raycast_result	r_result;
	t_render_thread		*r_thread;

	r_thread = (t_render_thread *)nr_thread;
	ray_index = r_thread->p_start - 1;
	while (++ray_index < r_thread->p_end)
	{
		ray = r_thread->game->rays[ray_index];
		r_result.distance = INT_MAX;
		r_result.p_loc = r_thread->current_level->player.position;
		r_result.ray = ray;
		if (ray.r_dir.vx > 0)
			get_x_pos_planes(&r_result, r_thread->current_level);
		else
			get_x_neg_planes(&r_result, r_thread->current_level);
		if (ray.r_dir.vy > 0)
			get_y_pos_planes(&r_result, r_thread->current_level);
		else
			get_y_neg_planes(&r_result, r_thread->current_level);
		if (r_result.distance == INT_MAX)
		{
			if (ray.r_dir.vz > 0)
				get_z_pos_planes(&r_result, r_thread->current_level);
			else
				get_z_neg_planes(&r_result, r_thread->current_level);
		}
		if (r_result.distance >= r_thread->game->current_level->player.render_distance
			|| r_result.distance == INT_MAX)
			bettermlx_pixel_put(r_thread->window, ray.pixel,
				create_icolor(0, 0, 0, 0), 1);
		else
		{
			if (r_result.plane.px == 1)
				draw_plane_ew_texture(r_thread, r_result, ray);
			else if (r_result.plane.py == 1)
				draw_plane_sn_texture(r_thread, r_result, ray);
			else if (r_result.plane.pz == 1)
				draw_plane_cf_texture(r_thread, r_result, ray);
		}
		draw_sprites(r_thread, &r_result, ray);
	}
	return (NULL);
}
