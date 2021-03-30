/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_init_xpm_image.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:36:17 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/25 12:35:36 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	*bettermlx_init_xpm_image(t_window *window, char *path)
{
	t_image		*image;

	image = ft_calloc(1, sizeof(t_image));
	if (image == NULL)
		return (NULL);
	image->width = 0;
	image->height = 0;
	image->img_ptr = mlx_xpm_file_to_image(window->mlx_ptr, \
	path, \
	&image->width, \
	&image->height);
	if (image->img_ptr == NULL)
	{
		free(image);
		return (NULL);
	}
	image->img_addr = mlx_get_data_addr(image->img_ptr, \
	&image->bits_per_pixel, \
	&image->size_line, \
	&image->endian);
	return (image);
}
