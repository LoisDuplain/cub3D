/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ew_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:13:12 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 16:13:22 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ew_texture(t_render_thread *r_thread, t_raycast_result r_result,
	t_ray ray)
{
	t_texture_id	texture_id;
	float			tx;
	float			ty;

	if (ray.r_dir.vx > 0)
		texture_id = EAST_TEXTURE;
	else
		texture_id = WEST_TEXTURE;
	if (texture_id == EAST_TEXTURE)
		tx = r_result.intrsct.vy - (int)r_result.intrsct.vy;
	else
		tx = 1 - r_result.intrsct.vy + (int)r_result.intrsct.vy;
	ty = 1 - r_result.intrsct.vz + (int)r_result.intrsct.vz;
	bettermlx_pixel_put(r_thread->window,
		ray.pixel,
		get_texture_color(
			r_thread->game->textures[texture_id],
			tx,
			ty),
		1 - r_result.distance / r_thread->world.player.render_distance);
}

