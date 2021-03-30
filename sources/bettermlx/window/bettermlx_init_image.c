/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_init_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:53:07 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/25 11:46:19 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	*bettermlx_init_image(t_window *window, int width, int height)
{
	t_image		*image;

	image = ft_calloc(1, sizeof(t_image));
	if (image == NULL)
		return (NULL);
	image->width = width;
	image->height = height;
	image->img_ptr = mlx_new_image(window->mlx_ptr, \
	width, \
	height);
	image->img_addr = mlx_get_data_addr(image->img_ptr, \
	&image->bits_per_pixel, \
	&image->size_line, \
	&image->endian);
	return (image);
}
