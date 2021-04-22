/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:35:42 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/22 19:38:23 by lduplain         ###   ########lyon.fr   */
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

float	get_sprite_distance(t_sprite sprite, t_ray ray, t_player player)
{
	float	div;

	div = sprite.plane.px * ray.r_dir.vx + sprite.plane.py * ray.r_dir.vy;
	if (div == 0)
		return (0);
	return ((-sprite.plane.px * player.position.vx
				- sprite.plane.py * player.position.vy
				- sprite.plane.dist) / div);
}

t_vector3	get_sprite_intrsct_point(t_player player, t_ray ray, float distance)
{
	t_vector3	intrsct;

	intrsct.vx = player.position.vx + ray.r_dir.vx * distance;
	intrsct.vy = player.position.vy + ray.r_dir.vy * distance;
	intrsct.vz = player.position.vz + ray.r_dir.vz * distance;
	return (intrsct);
}

float	get_sprite_ratio(t_vector3 intrsct, t_sprite sprite, t_player player)
{
	t_vector3	v2;
	t_vector3	u;

	u.vx = intrsct.vx - sprite.position.vx;
	u.vy = intrsct.vy - sprite.position.vy;
	v2 = normalize_vector(
			create_vector(
				sprite.position.vy - player.position.vy,
				player.position.vx - sprite.position.vx,
				0
				)
			);
	return ((u.vx * v2.vx) + (u.vy * v2.vy) + 0.5);
}

void	draw_sprites(t_render_thread *r_thread, t_raycast_result *r_result, t_ray ray)
{
	t_game		*game;
	int			sprite_index;
	t_sprite	sprite;
	float		distance;
	t_vector3	intrsct;
	float		r;

	game = r_thread->game;
	sprite_index = -1;
	while (++sprite_index < game->current_level->sprites_count)
	{
		sprite = game->current_level->sprites[sprite_index];
		if (!sprite.to_render)
			continue ;
		distance = get_sprite_distance(sprite, ray, game->world.player);
		if (distance <= 0 || distance > r_result->distance || distance > game->world.player.render_distance)
			continue ;
		intrsct = get_sprite_intrsct_point(game->world.player, ray, distance);
		r = get_sprite_ratio(intrsct, sprite, game->world.player);
		if (r < 0 || r > 1)
			continue ;
		t_color color = get_texture_color(
			r_thread->game->textures[SPRITE_TEXTURE], 1 - r, 1 - intrsct.vz);
		if (color.a == 255)
			continue ;
		r_result->distance = distance;
		bettermlx_pixel_put(r_thread->window, ray.pixel, color,
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
		draw_sprites(r_thread, &r_result, ray);
	}
	return (NULL);
}
