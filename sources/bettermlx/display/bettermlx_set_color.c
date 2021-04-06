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

void	bettermlx_set_color(t_image *image, int x, int y, t_color color)
{
	unsigned char	*position;

	position = bettermlx_get_memory_position(image, x, y);
	if (position == NULL)
		return ;
	position[0] = color.b;
	position[1] = color.g;
	position[2] = color.r;
	position[3] = color.a;
}
