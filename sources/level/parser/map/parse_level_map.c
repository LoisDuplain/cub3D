/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_level_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:21:52 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/01 19:21:33 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	parse_level_map(t_level *level)
{
	level->map_width = get_map_width(level);
	level->map_height = get_map_height(level);
	if (!are_valid_map_lines(level))
	{
		set_log_tlevel(level, ERROR, "Map line contains forbidden char.");
		return (FALSE);
	}
	if (!create_map_content(level))
		return (FALSE);
	if (!fill_map_content(level))
		return (FALSE);
	if (!single_player_map(level))
		return (FALSE);
	find_player(level);
	if (!validate_map(level, level->player.location.vx, level->player.location.vy))
	{
		set_log_tlevel(level, ERROR, "Player can go in void.");
		return (FALSE);
	}
	if (!create_map_content(level))
		return (FALSE);
	if (!fill_map_content(level))
		return (FALSE);
	convert_map(level);
	return (TRUE);
}
