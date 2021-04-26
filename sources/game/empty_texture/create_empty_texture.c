/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_empty_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:52:54 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/26 15:04:36 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_empty_texture	*create_empty_texture(void)
{
	t_empty_texture	*empty_texture;

	empty_texture = ft_calloc(1, sizeof(t_empty_texture));
	if (empty_texture == NULL)
		return (NULL);
	empty_texture->color = create_color((char)0, (char)0, (char)0, (char)0);
	empty_texture->texture_file_path = NULL;
	return (empty_texture);
}
