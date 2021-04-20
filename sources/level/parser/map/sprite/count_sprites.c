/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:50:07 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/20 18:01:37 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		count_sprites(t_level *level)
{
	int	counter;
	int	y;
	int	x;

	counter = 0;
	y = -1;
	while (++y < (int)level->map_height)
	{
		x = -1;
		while (++x < (int)level->map_width)
		{
			if (level->map_content[y][x] == 2)
				counter++;
		}
	}
	return (counter);
}
