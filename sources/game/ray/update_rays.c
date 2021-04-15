/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:17:42 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/15 16:15:10 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_rays(t_game *game)
{
	int		ray_index;
	double	p_cos;
	double	p_sin;
	double	y_cos;
	double	y_sin;
	t_ray	*ray;

	ray_index = -1;
	p_cos = cos(game->world.player.pitch);
	p_sin = sin(game->world.player.pitch);
	y_cos = cos(game->world.player.yaw);
	y_sin = sin(game->world.player.yaw);
	while (++ray_index < game->rays_size)
	{
		ray = &game->rays[ray_index];
		
		ray->r_direction.vx = ray->d_direction.vx;
		ray->r_direction.vy = p_cos * ray->d_direction.vy - p_sin * ray->d_direction.vz;
		ray->r_direction.vz = p_sin * ray->d_direction.vy + p_cos * ray->d_direction.vz;
/* 		ray->r_direction = create_vector(y_cos * ray->r_direction.vx - y_cos * ray->r_direction.vy,
										y_cos * ray->r_direction.vx + y_cos * ray->r_direction.vy,
										ray->r_direction.vz); */
	}
}
