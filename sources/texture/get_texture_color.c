/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:59:14 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/15 12:41:33 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	get_texture_color(t_texture *texture, float perc_x, float perc_y)
{
	int		texture_x;
	int		texture_y;

	if (texture == NULL)
		return (create_icolor(0, 0, 0, 0));
	if (texture->image == NULL)
		return (texture->color);
	texture_x = perc_x * texture->image->width;
	texture_y = perc_y * texture->image->height;
	return (bettermlx_get_color(texture->image, texture_x, texture_y));
}
