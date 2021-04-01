/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_player_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:12:17 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/01 17:16:03 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	single_player_map(t_level *level)
{
	t_bool		player_found;
	long long	line_index;
	long long	char_index;

	player_found = FALSE;
	line_index = -1;
	while (++line_index < (long long)level->map_height)
	{
		char_index = -1;
		while (++char_index < (long long)level->map_width)
		{
			if (!is_player_char(level->map_content[line_index][char_index]))
				continue ;
			if (player_found)
			{
				set_log_tlevel(level, ERROR, "Multiple players in map.");
				return (FALSE);
			}
			player_found = TRUE;
		}
	}
	if (!player_found)
		set_log_tlevel(level, ERROR, "No player in map.");
	return (player_found);
}
