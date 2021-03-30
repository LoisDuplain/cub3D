/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:31:29 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/30 08:50:56 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*create_texture(t_window *window, t_empty_texture *empty_texture)
{
	t_texture	*texture;

	texture = ft_calloc(1, sizeof(t_texture));
	if (texture == NULL)
		return (NULL);
	texture->color = empty_texture->color;
	texture->image = bettermlx_init_xpm_image(window, \
	empty_texture->texture_file_path);
	if (texture->image == NULL)
		return (destroy_texture(window, &texture));
	return (texture);
}
