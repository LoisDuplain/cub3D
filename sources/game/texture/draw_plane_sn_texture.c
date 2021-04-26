/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_plane_sn_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:14:59 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 18:43:46 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_plane_sn_texture(t_render_thread *r_thread,
	t_raycast_result r_result, t_ray ray)
{
	t_texture_id	texture_id;
	float			tx;
	float			ty;

	if (ray.r_dir.vy > 0)
		texture_id = SOUTH_TEXTURE;
	else
		texture_id = NORTH_TEXTURE;
	if (texture_id == SOUTH_TEXTURE)
		tx = 1 - r_result.intrsct.vx + (int)r_result.intrsct.vx;
	else
		tx = r_result.intrsct.vx - (int)r_result.intrsct.vx;
	ty = 1 - r_result.intrsct.vz + (int)r_result.intrsct.vz;
	bettermlx_pixel_put(r_thread->window,
		ray.pixel,
		get_texture_color(
			r_thread->game->textures[texture_id],
			tx,
			ty),
		1 - r_result.distance / r_thread->current_level->player.render_distance);
}
