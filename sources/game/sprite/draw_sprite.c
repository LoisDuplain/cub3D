/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:39:10 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 18:43:02 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(t_render_thread *r_thread, t_raycast_result *r_result,
	t_ray ray, t_sprite sprite)
{
	float		distance;
	t_vector3	intrsct;
	float		ratio;
	t_color		color;

	distance = get_sprite_distance(sprite, ray, r_thread->current_level->player);
	if (distance <= 0 || distance > r_result->distance
		|| distance > r_thread->current_level->player.render_distance)
		return ;
	intrsct = get_sprite_intrsct_point(r_thread->current_level->player, ray,
			distance);
	ratio = get_sprite_ratio(intrsct, sprite, r_thread->current_level->player);
	if (ratio < 0 || ratio > 1)
		return ;
	color = get_sprite_texture_color(r_thread, intrsct, ratio);
	if (color.a == 255)
		return ;
	r_result->distance = distance;
	bettermlx_pixel_put(r_thread->window, ray.pixel, color,
		1 - distance / r_thread->current_level->player.render_distance);
}
