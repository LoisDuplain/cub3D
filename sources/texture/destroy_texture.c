/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:36:50 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/30 08:55:23 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*destroy_texture(t_window *window, t_texture **texture)
{
	if (*texture != NULL)
	{
		bettermlx_destroy_image(window, &(*texture)->image);
		free(*texture);
		*texture = NULL;
	}
	return (NULL);
}
