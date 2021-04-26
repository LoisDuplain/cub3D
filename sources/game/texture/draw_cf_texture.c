/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cf_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:16:17 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 16:16:25 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_cf_texture(t_render_thread *r_thread, t_raycast_result r_result,
	t_ray ray)
{
	t_texture_id	texture_id;
	float			tx;
	float			ty;

	if (ray.r_dir.vz > 0)
		texture_id = CEILING_TEXTURE;
	else
		texture_id = FLOOR_TEXTURE;
	if (texture_id == CEILING_TEXTURE)
		ty = 1 - r_result.intrsct.vy + (int)r_result.intrsct.vy;
	else
		ty = r_result.intrsct.vy - (int)r_result.intrsct.vy;
	tx = r_result.intrsct.vx - (int)r_result.intrsct.vx;
	bettermlx_pixel_put(r_thread->window,
		ray.pixel,
		get_texture_color(
			r_thread->game->textures[texture_id],
			tx,
			ty),
		1 - r_result.distance / r_thread->world.player.render_distance);
}
