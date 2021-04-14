/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:59:14 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 16:48:36 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	get_texture_color(t_texture *texture, int x, int y)
{
	if (texture == NULL)
		return (create_icolor(0, 0, 0, 0));
	if (texture->image == NULL)
		return (texture->color);
	return (bettermlx_get_color(texture->image, x, y));
}
