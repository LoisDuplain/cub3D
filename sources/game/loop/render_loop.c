/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:35:42 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/27 14:44:34 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*render_loop(void *vr_thread)
{
	int					ray_index;
	t_ray				ray;
	t_raycast_result	r_result;
	t_render_thread		*r_thread;

	r_thread = (t_render_thread *)vr_thread;
	ray_index = r_thread->p_start - 1;
	while (++ray_index < r_thread->p_end)
	{
		ray = r_thread->game->rays[ray_index];
		r_result.distance = INT_MAX;
		r_result.p_loc = r_thread->lvl->player.position;
		r_result.ray = ray;
		get_planes(r_thread, ray, &r_result);
		if (r_result.distance >= r_thread->game->cur_lvl->player.render_distance
			|| r_result.distance == INT_MAX)
			bettermlx_pixel_put(r_thread->window, ray.pixel,
				create_icolor(0, 0, 0, 0), 1);
		else
			draw_plane_texture(r_thread, ray, r_result);
		draw_sprites(r_thread, &r_result, ray);
	}
	return (NULL);
}
