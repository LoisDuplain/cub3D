/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:17:42 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 19:51:25 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector3	rotate_pitch(t_vector3 d_dir, double p_cos, double p_sin)
{
	t_vector3	p_vector;

	p_vector.vx = d_dir.vx;
	p_vector.vy = p_cos * d_dir.vy - p_sin * d_dir.vz;
	p_vector.vz = p_sin * d_dir.vy + p_cos * d_dir.vz;
	return (p_vector);
}

t_vector3	rotate_yaw(t_vector3 p_vector, double y_cos, double y_sin)
{
	t_vector3	y_vector;

	y_vector.vx = y_cos * p_vector.vx - y_sin * p_vector.vy;
	y_vector.vy = y_sin * p_vector.vx + y_cos * p_vector.vy;
	y_vector.vz = p_vector.vz;
	return (y_vector);
}

void	update_rays(t_game *game)
{
	double	p_cos;
	double	p_sin;
	double	y_cos;
	double	y_sin;
	int		ray_index;

	p_cos = cos(game->cur_lvl->player.pitch);
	p_sin = sin(game->cur_lvl->player.pitch);
	y_cos = cos(game->cur_lvl->player.yaw);
	y_sin = sin(game->cur_lvl->player.yaw);
	ray_index = -1;
	while (++ray_index < game->rays_size)
	{
		game->rays[ray_index].r_dir = rotate_yaw(
				rotate_pitch(
					game->rays[ray_index].d_dir,
					p_cos,
					p_sin
					),
				y_cos,
				y_sin
				);
	}
}
