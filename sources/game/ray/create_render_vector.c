/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_render_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:58:48 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/13 12:06:50 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector3	create_render_vector(t_player player, t_window *window,
	int r_x, int r_y)
{
	t_vector3	direction;
	float		norm;

	direction = create_vector(2 * tan(player.fov_x * RADIAN * 0.5)
			/ window->real_width * (r_x - window->real_width * 0.5),
			-1,
			-2 * tan(player.fov_y * RADIAN * 0.5)
			/ window->real_height * (r_y - window->real_height * 0.5));
	norm = distance3(direction.vx, direction.vy, direction.vz);
	direction.vx /= norm;
	direction.vy /= norm;
	direction.vz /= norm;
	return (direction);
}
