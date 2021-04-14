/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_south_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:07:22 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 17:05:33 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	parse_south_param(t_level *level,
	char **splitted,
	size_t splitted_size)
{
	if (splitted_size < 2)
	{
		set_log_tlevel(level, ERROR, "Not enough arguments in south param.");
		return (FALSE);
	}
	if (splitted_size > 2)
	{
		set_log_tlevel(level, ERROR, "Too many arguments in south param.");
		return (FALSE);
	}
	return (parse_empty_texture(level, \
	&level->empty_textures[SOUTH_TEXTURE], splitted[1]));
}
