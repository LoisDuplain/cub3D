/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:35:42 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/16 10:55:28 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*render_loop(void *nr_thread)
{
	int					ray_index;
	t_ray				ray;
	t_raycast_result	r_result;
	t_render_thread		*r_thread;
	float				tx;
	float				ty;

	r_thread = (t_render_thread *)nr_thread;
	ray_index = r_thread->p_start - 1;
	while (++ray_index < r_thread->p_end)
	{
		ray = r_thread->game->rays[ray_index];
		r_result.distance = INT_MAX;
		r_result.p_loc = r_thread->world.player.location;
		r_result.ray = ray;
		if (ray.r_dir.vx > 0)
			get_x_pos_planes(&r_result, r_thread->world, r_thread->m_content);
		else
			get_x_neg_planes(&r_result, r_thread->world, r_thread->m_content);
		if (ray.r_dir.vy > 0)
			get_y_pos_planes(&r_result, r_thread->world, r_thread->m_content);
		else
			get_y_neg_planes(&r_result, r_thread->world, r_thread->m_content);
		if (r_result.distance == INT_MAX)
		{
			if (ray.r_dir.vz > 0)
				get_z_pos_planes(&r_result, r_thread->world);
			else
				get_z_neg_planes(&r_result, r_thread->world);
		}
		if (r_result.distance == INT_MAX)
			bettermlx_pixel_put(r_thread->window, ray.pixel, create_icolor(0, 0, 0, 0), 1);
		else
		{
			if (r_result.plane.px == 1)
			{
				if (ray.r_dir.vx > 0)
				{
					t_texture *east_texture = r_thread->game->textures[EAST_TEXTURE];
					tx = r_result.intrsct.vy - (int)r_result.intrsct.vy;
					ty = 1 - r_result.intrsct.vz + (int)r_result.intrsct.vz;
					bettermlx_pixel_put(r_thread->window, ray.pixel, get_texture_color(east_texture, tx, ty), 1 - r_result.distance / r_thread->world.player.render_distance);
				}
				else
				{
					t_texture *west_texture = r_thread->game->textures[WEST_TEXTURE];
					tx = 1 - r_result.intrsct.vy + (int)r_result.intrsct.vy;
					ty = 1 - r_result.intrsct.vz + (int)r_result.intrsct.vz;
					bettermlx_pixel_put(r_thread->window, ray.pixel, get_texture_color(west_texture, tx, ty), 1 - r_result.distance / r_thread->world.player.render_distance);
				}
			}
			else if (r_result.plane.py == 1)
			{
				if (ray.r_dir.vy > 0)
				{
					t_texture *south_texture = r_thread->game->textures[SOUTH_TEXTURE];
					tx = 1 - r_result.intrsct.vx + (int)r_result.intrsct.vx;
					ty = 1 - r_result.intrsct.vz + (int)r_result.intrsct.vz;
					bettermlx_pixel_put(r_thread->window, ray.pixel, get_texture_color(south_texture, tx, ty), 1 - r_result.distance / r_thread->world.player.render_distance);
				}
				else
				{
					t_texture *north_texture = r_thread->game->textures[NORTH_TEXTURE];
					tx = r_result.intrsct.vx - (int)r_result.intrsct.vx;
					ty = 1 - r_result.intrsct.vz + (int)r_result.intrsct.vz;
					bettermlx_pixel_put(r_thread->window, ray.pixel, get_texture_color(north_texture, tx, ty), 1 - r_result.distance / r_thread->world.player.render_distance);
				}
			}
			else if (r_result.plane.pz == 1)
			{
				if (ray.r_dir.vz > 0)
				{
					t_texture *ceiling_texture = r_thread->game->textures[CEILING_TEXTURE];
					tx = r_result.intrsct.vx - (int)r_result.intrsct.vx;
					ty = 1 - r_result.intrsct.vy + (int)r_result.intrsct.vy;
					bettermlx_pixel_put(r_thread->window, ray.pixel, get_texture_color(ceiling_texture, tx, ty), 1 - r_result.distance / r_thread->world.player.render_distance);
				}
				else
				{
					t_texture *floor_texture = r_thread->game->textures[FLOOR_TEXTURE];
					tx = r_result.intrsct.vx - (int)r_result.intrsct.vx;
					ty = r_result.intrsct.vy - (int)r_result.intrsct.vy;
					bettermlx_pixel_put(r_thread->window, ray.pixel, get_texture_color(floor_texture, tx, ty), 1 - r_result.distance / r_thread->world.player.render_distance);
				}
			}
		}
	}
	return (NULL);
}
