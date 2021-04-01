/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:11:43 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/01 17:28:29 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_player(t_level *level)
{
	char		**map;
	long long	line_index;
	long long	char_index;

	map = level->map_content;
	line_index = -1;
	while (++line_index < (long long)level->map_height)
	{
		char_index = -1;
		while (++char_index < (long long)level->map_width)
		{
			if (!is_player_char(map[line_index][char_index]))
				continue ;
			level->player.location = create_vector(char_index, line_index, 0.5);
			level->player.spawn_facing = \
			get_player_spawn_facing(map[line_index][char_index]);
		}
	}
}
