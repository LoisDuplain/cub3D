/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_set_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:08:43 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/06 15:08:34 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bettermlx_set_color(t_image *image, t_vector3 pixel_coordinates, t_color color, float darkness)
{
	unsigned char	*position;

	position = bettermlx_get_memory_position(image, pixel_coordinates.vx,
		pixel_coordinates.vy);
	if (position == NULL)
		return ;
	position[0] = color.b * darkness;
	position[1] = color.g * darkness;
	position[2] = color.r * darkness;
	position[3] = color.a;
}
