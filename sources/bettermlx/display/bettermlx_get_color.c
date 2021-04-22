/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_get_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:04:11 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/22 15:33:43 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	bettermlx_get_color(t_image *image, int x, int y)
{
	unsigned char	*position;

	position = bettermlx_get_memory_position(image, x, y);
	if (position == NULL)
		return (create_color(0, 0, 0, 0));
	return (create_color(position[3], position[2], position[1], position[0]));
}
