/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_destroy_image.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:41:36 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/30 11:09:51 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*bettermlx_destroy_image(t_window *window, t_image **image)
{
	if (*image != NULL)
	{
		mlx_destroy_image(window->mlx_ptr, (*image)->img_ptr);
		free(*image);
		*image = NULL;
	}
	return (NULL);
}
