/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_draw_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:48:28 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/06 15:08:28 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bettermlx_draw_line(
	t_window *window,
	t_vector3 xy1,
	t_vector3 xy2,
	t_color color)
{
	float		length;
	float		dx;
	float		dy;
	t_vector3	xy;
	int			i;

	length = ft_abs(xy2.vy - xy1.vy);
	if (ft_abs(xy2.vx - xy1.vx) > length)
		length = ft_abs(xy2.vx - xy1.vx);
	dx = (xy2.vx - xy1.vx) / length;
	dy = (xy2.vy - xy1.vy) / length;
	xy = create_vector(xy1.vx + 0.5, xy1.vy + 0.5, 0);
	i = 1;
	while (i <= length)
	{
		bettermlx_pixel_put(window, xy, color, 1);
		xy.vx += dx;
		xy.vy += dy;
		i++;
	}
}
