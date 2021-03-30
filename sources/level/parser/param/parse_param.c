/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:40:13 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/30 11:31:13 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	parse_param(t_level *level,
	t_param_type param_type,
	char **splitted,
	size_t splitted_size)
{
	if (param_type == RESOLUTION_PARAM)
		return (parse_resolution_param(level, splitted, splitted_size));
	else if (param_type == NORTH_PARAM)
		return (parse_north_param(level, splitted, splitted_size));
	else if (param_type == SOUTH_PARAM)
		return (parse_south_param(level, splitted, splitted_size));
	else if (param_type == WEST_PARAM)
		return (parse_west_param(level, splitted, splitted_size));
	else if (param_type == EAST_PARAM)
		return (parse_east_param(level, splitted, splitted_size));
	else if (param_type == UNKNOWN)
	{
		set_log_tlevel(level, ERROR, "Unknown param type in level file.");
		return (FALSE);
	}
	set_log_tlevel(level, ERROR, "Can't find good parser for that param type.");
	return (FALSE);
}
