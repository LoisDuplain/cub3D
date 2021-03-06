/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_pixel_put.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:26:34 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/21 19:00:01 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bettermlx_pixel_put(
	t_window *window,
	t_vector3 pixel_coordinates,
	t_color color,
	float darkness)
{
	int		ay;
	int		my;
	int		ax;
	int		mx;

	ay = ((int)pixel_coordinates.vy) * window->divider;
	my = ay + window->divider;
	mx = ((int)pixel_coordinates.vx) * window->divider + window->divider;
	while (ay < my)
	{
		ax = ((int)pixel_coordinates.vx) * window->divider;
		while (ax < mx)
		{
			bettermlx_set_color(window->image, create_vector(ax, ay, 0),
				color, darkness);
			ax++;
		}
		ay++;
	}
}
