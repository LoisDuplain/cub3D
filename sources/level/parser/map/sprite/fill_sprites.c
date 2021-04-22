/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:39:20 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/22 16:20:22 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_sprites(t_level *level)
{
	int	sprite_index;
	int	y;
	int	x;

	sprite_index = 0;
	y = -1;
	while (++y < (int)level->map_height)
	{
		x = -1;
		while (++x < (int)level->map_width)
		{
			if (level->map_content[y][x] != 2)
				continue ;
			level->sprites[sprite_index++] = create_sprite(
					create_plane(0, 0, 0, 0),
					create_vector(x + 0.5, y + 0.5, 0)
					);
		}
	}
}
