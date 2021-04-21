/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:35:42 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/21 18:51:56 by lduplain         ###   ########lyon.fr   */
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

void	draw_sn_texture(t_render_thread *r_thread, t_raycast_result r_result,
	t_ray ray)
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
		1 - r_result.distance / r_thread->world.player.render_distance);
}

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

void	draw_sprites(t_render_thread *r_thread, t_raycast_result r_result, t_ray ray)
{
	t_game		*game;
	t_window	*window;
	t_level		*current_level;
	int			sprite_index;
	t_sprite	sprite;
	float		div;
	float		distance;
	t_vector3	intrsct;
	t_vector3	projected;
	t_vector3	u;
	t_vector3	v;
	t_vector3	v_prime;
	t_vector3	v2;
	float		r;

	game = r_thread->game;
	window = r_thread->window;
	current_level = game->current_level;
	sprite_index = -1;
	while (++sprite_index < current_level->sprites_count)
	{
		sprite = current_level->sprites[sprite_index];
		div = sprite.plane.px * ray.r_dir.vx + sprite.plane.py * ray.r_dir.vy;
		if (div == 0)
			continue ;
		distance = -(sprite.plane.px * game->world.player.position.vx
					+ sprite.plane.py * game->world.player.position.vy
					+ sprite.plane.dist)
					/ div;
		if (distance <= 0 || distance > game->world.player.render_distance || distance > r_result.distance)
			continue ;
		intrsct.vx = game->world.player.position.vx + ray.r_dir.vx * distance;
		intrsct.vy = game->world.player.position.vy + ray.r_dir.vy * distance;
		intrsct.vz = game->world.player.position.vz + ray.r_dir.vz * distance;
		if (distance_square2(
			sprite.position.vx - intrsct.vx,
			sprite.position.vy - intrsct.vy
		) > 0.25)
			continue ;
		projected = create_vector(sprite.position.vx, intrsct.vy, 0);
		u = sub_vector_vector(projected, intrsct);
		v = sub_vector_vector(sprite.position, game->world.player.position);
		v_prime = create_vector(v.vy, -v.vx, 0);
		v2 = normalize_vector(v_prime);
		r = (u.vx * v2.vx) + (u.vy * v2.vy) + (u.vz * v2.vz) + 0.5;
		if (r < 0 || r > 1)
			continue ;
		bettermlx_pixel_put(r_thread->window,
			ray.pixel,
			get_texture_color(
				r_thread->game->textures[SPRITE_TEXTURE],
				/* Texture x */ r,
				/* Texture y */ 1 - intrsct.vz),
			1 - distance / r_thread->world.player.render_distance);
	}
}

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
		r_result.p_loc = r_thread->world.player.position;
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
		if (r_result.distance == INT_MAX || r_result.distance >= r_thread->game->world.player.render_distance)
			bettermlx_pixel_put(r_thread->window, ray.pixel, create_icolor(0, 0, 0, 0), 1);
		else
		{
			if (r_result.plane.px == 1)
				draw_ew_texture(r_thread, r_result, ray);
			else if (r_result.plane.py == 1)
				draw_sn_texture(r_thread, r_result, ray);
			else if (r_result.plane.pz == 1)
				draw_cf_texture(r_thread, r_result, ray);
		}
		draw_sprites(r_thread, r_result, ray);
	}
	return (NULL);
}
