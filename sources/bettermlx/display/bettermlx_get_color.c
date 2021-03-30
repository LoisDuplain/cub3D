/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_get_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:04:11 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/25 11:45:45 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	bettermlx_get_color(t_image *image, int x, int y)
{
	unsigned char	*position;

	position = bettermlx_get_memory_position(image, x, y);
	if (position == NULL)
		return (create_color(0, 0, 0, 0));
	return (create_color(position[3], position[0], position[1], position[2]));
}
