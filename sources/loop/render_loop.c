/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:35:42 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/13 17:15:19 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool		is_in_world(t_vector3 intrsct, t_world world)
{
	if (intrsct.vx >= 0 && intrsct.vx <= world.x_planes_size
		&& intrsct.vy >= 0 && intrsct.vy <= world.y_planes_size
		&& intrsct.vz >= 0 && intrsct.vz <= 1)
		return (TRUE);
	return (FALSE);
}

t_vector3	get_intrsct_point(t_vector3 p_loc, t_vector3 r_dir, t_plane plane, float distance)
{
	t_vector3	intrsct;

	intrsct.vx = p_loc.vx + r_dir.vx * distance;
	intrsct.vy = p_loc.vy + r_dir.vy * distance;
	intrsct.vz = p_loc.vz + r_dir.vz * distance;
	if (plane.px == 1)
		if (ft_fabs(intrsct.vx - plane.dist) <= 0.1)
			intrsct.vx = plane.dist;
	if (plane.py == 1)
		if (ft_fabs(intrsct.vy - plane.dist) <= 0.1)
			intrsct.vy = plane.dist;
	return (intrsct);
}

t_bool 	intrsct_x_plane(t_raycast_result *r_result, t_world world, char **map_content, t_plane plane)
{
	float		distance;
	t_vector3	intrsct;
	int			sub;

	distance = -(r_result->p_loc.vx - plane.dist) / r_result->r_dir.vx;
	if (distance < 0)
		return (FALSE);
	if (distance > r_result->distance || distance > RENDER_DISTANCE)
		return (TRUE);
	intrsct = get_intrsct_point(r_result->p_loc, r_result->r_dir, plane, distance);
	if (intrsct.vz <= 0 || intrsct.vz >= 1)
		return (TRUE);
	sub = 0;
	if (r_result->r_dir.vx < 0)
		sub = 1;
	if (is_in_world(intrsct, world)
		&& map_content[(int)intrsct.vy][(int)intrsct.vx - sub] == 1)
	{
		r_result->distance = distance;
		r_result->color = create_color(0, 255, 0, 0);
		return (TRUE);
	}
	return (FALSE);
}

void	get_x_pos_planes(t_raycast_result *r_result, t_world world, char **map_content)
{
	int			x_index;
	t_plane		plane;
	t_bool		intrsct;

	x_index = (int)r_result->p_loc.vx - 1;
	while (++x_index < world.x_planes_size && x_index < r_result->p_loc.vx + RENDER_DISTANCE - 1)
	{
		plane = world.x_planes[x_index];
		intrsct = intrsct_x_plane(r_result, world, map_content, plane);
		if (!intrsct)
			continue ;
		break;
	}
}

void	get_x_neg_planes(t_raycast_result *r_result, t_world world, char **map_content)
{
	int			x_index;
	t_plane		plane;
	t_bool		intrsct;

	x_index = (int)r_result->p_loc.vx + 1;
	while (--x_index >= 0 && x_index >= r_result->p_loc.vx - RENDER_DISTANCE - 1)
	{
		plane = world.x_planes[x_index];
		intrsct = intrsct_x_plane(r_result, world, map_content, plane);
		if (!intrsct)
			continue ;
		break ;
	}
}

t_bool	intrsct_y_plane(t_raycast_result *r_result, t_world world, char **map_content, t_plane plane)
{
	float		distance;
	t_vector3	intrsct;
	int			sub;
	
	distance = -(r_result->p_loc.vy - plane.dist) / r_result->r_dir.vy;
	if (distance < 0)
		return (FALSE);
	if (distance > r_result->distance || distance > RENDER_DISTANCE)
		return (TRUE);
	intrsct = get_intrsct_point(r_result->p_loc, r_result->r_dir, plane, distance);
	if (intrsct.vz <= 0 || intrsct.vz >= 1)
		return (TRUE);
	sub = 0;
	if (r_result->r_dir.vy < 0)
		sub = 1;
	if (is_in_world(intrsct, world)
		&& map_content[(int)intrsct.vy - sub][(int)intrsct.vx] == 1)
	{
		r_result->distance = distance;
		r_result->color = create_color(0, 0, 0, 255);
		return (TRUE);
	}
	return (FALSE);
}

void	get_y_pos_planes(t_raycast_result *r_result, t_world world, char **map_content)
{
	int			y_index;
	t_plane		plane;
	t_bool	intrsct;

	y_index = (int)r_result->p_loc.vy - 1;
	while (++y_index < world.y_planes_size && y_index < r_result->p_loc.vy + RENDER_DISTANCE - 1)
	{
		plane = world.y_planes[y_index];
		intrsct = intrsct_y_plane(r_result, world, map_content, plane);
		if (!intrsct)
			continue ;
		break ;
	}
}

void	get_y_neg_planes(t_raycast_result *r_result, t_world world, char **map_content)
{
	int			y_index;
	t_plane		plane;
	t_bool	intrsct;

	y_index = (int)r_result->p_loc.vy + 1;
	while (--y_index >= 0 && y_index >= r_result->p_loc.vy - RENDER_DISTANCE - 1)
	{
		plane = world.y_planes[y_index];
		intrsct = intrsct_y_plane(r_result, world, map_content, plane);
		if (!intrsct)
			continue ;
		break ;
	}
}

void	get_z_pos_planes(t_raycast_result *r_result)
{
	float	distance;

	distance = -(r_result->p_loc.vz - 1) / r_result->r_dir.vz;
	if (distance < 0 || distance > r_result->distance)
		return ;
	r_result->distance = distance;
	r_result->color = create_color(0, 0, 255, 0);
}

void	get_z_neg_planes(t_raycast_result *r_result)
{
	float	distance;

	distance = -r_result->p_loc.vz / r_result->r_dir.vz;
	if (distance < 0 || distance > r_result->distance)
		return ;
	r_result->distance = distance;
	r_result->color = create_color(0, 0, 125, 0);
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
		r_result.color = create_color(0, 0, 0, 0);
		r_result.p_loc = r_thread->world.player.location;
		r_result.r_dir = ray.direction;
		if (ray.direction.vx > 0)
			get_x_pos_planes(&r_result, r_thread->world, r_thread->m_content);
		else
			get_x_neg_planes(&r_result, r_thread->world, r_thread->m_content);
		if (ray.direction.vy > 0)
			get_y_pos_planes(&r_result, r_thread->world, r_thread->m_content);
		else
			get_y_neg_planes(&r_result, r_thread->world, r_thread->m_content);
		if (r_result.distance == INT_MAX)
		{
			if (ray.direction.vz > 0)
				get_z_pos_planes(&r_result);
			else
				get_z_neg_planes(&r_result);
		}
		bettermlx_pixel_put(r_thread->window, ray.pixel, r_result.color, 1 - r_result.distance / RENDER_DISTANCE);
		// bettermlx_pixel_put(r_thread->window, ray.pixel, r_result.color, 1);
	}
	pthread_exit(NULL);
	return (NULL);
}
