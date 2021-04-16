/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution_param.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:46:00 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/16 11:55:10 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	parse_resolution_param(t_level *level, \
	char **splitted, \
	size_t splitted_size)
{
	if (splitted_size < 3)
	{
		set_log_tlevel(level, ERROR, "Not enough arguments in res. param.");
		return (FALSE);
	}
	if (splitted_size > 3)
	{
		set_log_tlevel(level, ERROR, "Too many arguments in res. param.");
		return (FALSE);
	}
	level->window_width = ft_atoi(splitted[1]);
	if (level->window_width <= 200)
		level->window_width = 200;
	if (level->window_width > 3200)
		level->window_width = 3200;
	level->window_height = ft_atoi(splitted[2]);
	if (level->window_height <= 200)
		level->window_height = 200;
	if (level->window_height > 1800)
		level->window_height = 1800;
	return (TRUE);
}
