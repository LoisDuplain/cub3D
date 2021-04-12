/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:35:42 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/09 16:51:54 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_x_pos_planes(t_raycast_result *r_result, t_world world, char **map_content)
{
	int			x_index;
	t_plane		plane;
	float		distance;
	t_vector3	intrsct;

	x_index = (int)r_result->p_loc.vx - 1;
	while (++x_index < world.x_planes_size)
	{
		plane = world.x_planes[x_index];
		distance = -(r_result->p_loc.vx - plane.dist) / r_result->r_dir.vx;
		if (distance < 0)
			continue;
		if (distance > r_result->distance)
			break;
		intrsct.vx = (r_result->p_loc.vx + r_result->r_dir.vx * distance);
		intrsct.vy = (r_result->p_loc.vy + r_result->r_dir.vy * distance);
		intrsct.vz = (r_result->p_loc.vz + r_result->r_dir.vz * distance);
		if (intrsct.vx >= 0 && intrsct.vx <= world.x_planes_size
			&& intrsct.vy >= 0 && intrsct.vy <= world.y_planes_size
			&& intrsct.vz >= 0 && intrsct.vz <= 1
			&& map_content[(int)intrsct.vy][(int)intrsct.vx] == 1)
		{
			r_result->distance = distance;
			r_result->color = create_color(0, 255, 0, 0);
			break;
		}
	}
}

void	get_x_neg_planes(t_raycast_result *r_result, t_world world, char **map_content)
{
	int			x_index;
	t_plane		plane;
	float		distance;
	t_vector3	intrsct;

	x_index = (int)r_result->p_loc.vx + 1;
	while (--x_index >= 0)
	{
		plane = world.x_planes[x_index];
		distance = -(r_result->p_loc.vx - plane.dist) / r_result->r_dir.vx;
		if (distance < 0)
			continue;
		if (distance > r_result->distance)
			break;
		intrsct.vx = (r_result->p_loc.vx + r_result->r_dir.vx * distance);
		intrsct.vy = (r_result->p_loc.vy + r_result->r_dir.vy * distance);
		intrsct.vz = (r_result->p_loc.vz + r_result->r_dir.vz * distance);
		if (intrsct.vx >= 0 && intrsct.vx <= world.x_planes_size
			&& intrsct.vy >= 0 && intrsct.vy <= world.y_planes_size
			&& intrsct.vz >= 0 && intrsct.vz <= 1
			&& map_content[(int)intrsct.vy][(int)intrsct.vx] == 1)
		{
			r_result->distance = distance;
			r_result->color = create_color(0, 125, 0, 0);
			break;
		}
	}
}

void	get_y_pos_planes(t_raycast_result *r_result, t_world world, char **map_content)
{
	int			y_index;
	t_plane		plane;
	float		distance;
	t_vector3	intrsct;

	y_index = (int)r_result->p_loc.vy - 1;
	while (++y_index < world.y_planes_size)
	{
		plane = world.y_planes[y_index];
		distance = -(r_result->p_loc.vy - plane.dist) / r_result->r_dir.vy;
		if (distance < 0)
			continue;
		if (distance > r_result->distance)
			break;
		intrsct.vx = (r_result->p_loc.vx + r_result->r_dir.vx * distance);
		intrsct.vy = (r_result->p_loc.vy + r_result->r_dir.vy * distance);
		intrsct.vz = (r_result->p_loc.vz + r_result->r_dir.vz * distance);
		if (intrsct.vx >= 0 && intrsct.vx <= world.x_planes_size
			&& intrsct.vy >= 0 && intrsct.vy <= world.y_planes_size
			&& intrsct.vz >= 0 && intrsct.vz <= 1
			&& map_content[(int)intrsct.vy][(int)intrsct.vx] == 1)
		{
			r_result->distance = distance;
			r_result->color = create_color(0, 0, 0, 255);
			break;
		}
	}
}

void	get_y_neg_planes(t_raycast_result *r_result, t_world world, char **map_content)
{
	int			y_index;
	t_plane		plane;
	float		distance;
	t_vector3	intrsct;

	y_index = (int)r_result->p_loc.vy + 1;
	while (--y_index >= 0)
	{
		plane = world.y_planes[y_index];
		distance = -(r_result->p_loc.vy - plane.dist) / r_result->r_dir.vy;
		if (distance < 0)
			continue;
		if (distance > r_result->distance)
			break;
		intrsct.vx = (r_result->p_loc.vx + r_result->r_dir.vx * distance);
		intrsct.vy = (r_result->p_loc.vy + r_result->r_dir.vy * distance);
		intrsct.vz = (r_result->p_loc.vz + r_result->r_dir.vz * distance);
		if (intrsct.vx >= 0 && intrsct.vx <= world.x_planes_size
			&& intrsct.vy >= 0 && intrsct.vy <= world.y_planes_size
			&& intrsct.vz >= 0 && intrsct.vz <= 1
			&& map_content[(int)intrsct.vy][(int)intrsct.vx] == 1)
		{
			r_result->distance = distance;
			r_result->color = create_color(0, 0, 0, 125);
			break;
		}
	}
}

void	get_z_pos_planes(t_raycast_result *r_result, t_world world)
{
	t_plane		plane;
	float		distance;

	plane = world.z_planes[1];
	distance = -(r_result->p_loc.vz - plane.dist) / r_result->r_dir.vz;
	if (distance < 0)
		return ;
	if (distance > r_result->distance)
		return ;
	r_result->distance = distance;
	r_result->color = create_color(0, 0, 255, 0);
}

void	get_z_neg_planes(t_raycast_result *r_result, t_world world)
{
	t_plane		plane;
	float		distance;

	plane = world.z_planes[0];
	distance = -(r_result->p_loc.vz - plane.dist) / r_result->r_dir.vz;
	if (distance < 0)
		return ;
	if (distance > r_result->distance)
		return ;
	r_result->distance = distance;
	r_result->color = create_color(0, 0, 125, 0);
}

void	render_loop(t_game *game, t_window *window)
{
	int					ray_index;
	t_ray				ray;
	t_raycast_result	r_result;

	ray_index = -1;
	while (++ray_index < game->rays_size)
	{
		ray = game->rays[ray_index];
		ray.direction = rotate_vector_z(ray.direction, game->world.player.yaw * RADIAN);
		r_result.distance = INT_MAX;
		r_result.color = create_color(0, 0, 0, 0);
		r_result.p_loc = game->world.player.location;
		r_result.r_dir = ray.direction;
		if (ray.direction.vx > 0)
			get_x_pos_planes(&r_result, game->world, game->current_level->map_content);
		else
			get_x_neg_planes(&r_result, game->world, game->current_level->map_content);
		if (ray.direction.vy > 0)
			get_y_pos_planes(&r_result, game->world, game->current_level->map_content);
		else
			get_y_neg_planes(&r_result, game->world, game->current_level->map_content);
		if (ray.direction.vz > 0)
			get_z_pos_planes(&r_result, game->world);
		else
			get_z_neg_planes(&r_result, game->world);
		bettermlx_pixel_put(window, ray.pixel, r_result.color, 1);
	}
	bettermlx_render(window);
}
