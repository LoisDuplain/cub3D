/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:35:42 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/08 18:00:26 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	intrsct(t_game *game, t_world world, t_plane plane, t_vector3 ray_dir, t_player player)
{
	float		divider;
	float		distance;
	t_vector3	intersect_point;

	divider = plane.px * ray_dir.vx + plane.py * ray_dir.vy + plane.pz * ray_dir.vz;
	if (divider == 0)
		return (INT_MAX);
	distance = -(plane.px * player.location.vx + plane.py * player.location.vy + plane.pz * player.location.vz - plane.dist) / divider;
	if (distance >= 0)
	{
		intersect_point.vx = (player.location.vx + ray_dir.vx * distance);
		intersect_point.vy = (player.location.vy + ray_dir.vy * distance);
		intersect_point.vz = (player.location.vz + ray_dir.vz * distance);
		if ((intersect_point.vx >= 0 && intersect_point.vx < world.x_planes_size - 1
			&& intersect_point.vy >= 0 && intersect_point.vy < world.y_planes_size - 1
			&& intersect_point.vz >= 0 && intersect_point.vz <= 1
			&& game->current_level->map_content[(int)intersect_point.vy][(int)intersect_point.vx] == 1)
			|| plane.pz == 1)
			return (distance);
		return (INT_MAX);
	}
	return (INT_MAX);
}

void	render_loop(t_game *game, t_window *window)
{
	int			ray_index;
	t_ray		ray;
	t_world		world;
	int			x_plane_index;
	int			y_plane_index;
	t_plane		plane;
	int			x_raycast_result;
	int			y_raycast_result;
	int			z_raycast_result;
	int			temp;

	bettermlx_clean_display(window);
	world = game->world;
	ray_index = -1;
	while (++ray_index < game->rays_size)
	{
		ray = game->rays[ray_index];
		ray.direction = rotate_vector_z(ray.direction, game->world.player.yaw * RADIAN);
		x_raycast_result = INT_MAX;
		x_plane_index = -1;
		while (++x_plane_index < world.x_planes_size)
		{
			plane = world.x_planes[x_plane_index];
			temp = intrsct(game, world, plane, ray.direction, world.player);
			if (temp < x_raycast_result)
				x_raycast_result = temp;
		}
		y_raycast_result = INT_MAX;
		y_plane_index = -1;
		while (++y_plane_index < world.y_planes_size)
		{
			plane = world.y_planes[y_plane_index];
			temp = intrsct(game, world, plane, ray.direction, world.player);
			if (temp < y_raycast_result)
				y_raycast_result = temp;
		}
		z_raycast_result = INT_MAX;
		plane = create_plane(0, 0, 1, 0);
		temp = intrsct(game, world, plane, ray.direction, world.player);
		if (temp < z_raycast_result)
			z_raycast_result = temp;
		plane = create_plane(0, 0, 1, 1);
		temp = intrsct(game, world, plane, ray.direction, world.player);
		if (temp < z_raycast_result)
			z_raycast_result = temp;
		if (x_raycast_result < y_raycast_result && x_raycast_result < z_raycast_result)
		{
			bettermlx_pixel_put(window, ray.pixel, create_color(0, 255, 0, 0), 1);
		}
		else if (y_raycast_result < x_raycast_result && y_raycast_result < z_raycast_result)
		{
			bettermlx_pixel_put(window, ray.pixel, create_color(0, 0, 0, 255), 1);
		}
		else
		{
			bettermlx_pixel_put(window, ray.pixel, create_color(0, 0, 255, 0), 1);
		}
	}
	bettermlx_render(window);
}
