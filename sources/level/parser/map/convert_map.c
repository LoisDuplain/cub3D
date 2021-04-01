/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:21:23 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/01 17:50:10 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	convert_map(t_level *level)
{
	char		**map;
	char		c;
	long long	l_index;
	long long	c_index;

	map = level->map_content;
	l_index = -1;
	while (++l_index < (long long)level->map_height)
	{
		c_index = -1;
		while (++c_index < (long long)level->map_width)
		{
			c = map[l_index][c_index];
			if (c == 0 || c == ' ')
				map[l_index][c_index] = -2;
			else if (c == '0' || is_player_char(c))
				map[l_index][c_index] = 0;
			else if (c == '1')
				map[l_index][c_index] = 1;
			else if (c == '2')
				map[l_index][c_index] = 2;
		}
	}
}
