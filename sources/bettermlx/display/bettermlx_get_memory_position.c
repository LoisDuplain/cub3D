/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_get_memory_position.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:59:03 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/25 11:45:47 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned char	*bettermlx_get_memory_position(t_image *image, int x, int y)
{
	unsigned char	*position;

	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return (NULL);
	position = (unsigned char *)image->img_addr + y * image->size_line + x * 4;
	return (position);
}
