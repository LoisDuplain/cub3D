/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ceiling_param.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 09:07:55 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/31 09:19:05 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	parse_ceiling_param(t_level *level,
	char **splitted,
	size_t splitted_size)
{
	if (splitted_size < 2)
	{
		set_log_tlevel(level, ERROR, "Not enough arguments in ceiling param.");
		return (FALSE);
	}
	if (splitted_size > 3)
	{
		set_log_tlevel(level, ERROR, "Too many arguments in ceiling param.");
		return (FALSE);
	}
	if (splitted_size == 3)
	{
		if (ft_strcmp(splitted[1], "skybox") != 0)
		{
			set_log_tlevel(level, ERROR, "Wrong argument in ceiling param. \
			\nDid you mean \"skybox\" ?");
			return (FALSE);
		}
		level->ceiling_is_skybox = TRUE;
		return (parse_empty_texture(level, \
		&level->ceiling_empty_texture, splitted[2]));
	}
	return (parse_empty_texture(level, \
	&level->ceiling_empty_texture, splitted[1]));
}
