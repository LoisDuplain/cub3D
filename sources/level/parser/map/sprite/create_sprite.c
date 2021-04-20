/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:04:02 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/20 12:35:19 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	create_sprite(t_plane plane, t_vector3 position)
{
	t_sprite	sprite;

	sprite.plane = plane;
	sprite.position = position;
	return (sprite);
}
