/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_texture_color.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:24:04 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 16:24:15 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color		get_sprite_texture_color(t_render_thread *r_thread, t_vector3 intrsct,
	float ratio)
{
	return (get_texture_color(
		r_thread->game->textures[SPRITE_TEXTURE], 1 - ratio,
		1 - intrsct.vz));
}
