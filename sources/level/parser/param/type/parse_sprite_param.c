/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprite_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 08:11:59 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/31 16:46:45 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	parse_sprite_param(t_level *level,
	char **splitted,
	size_t splitted_size)
{
	if (splitted_size < 2)
	{
		set_log_tlevel(level, ERROR, "Not enough arguments in sprite param.");
		return (FALSE);
	}
	if (splitted_size > 2)
	{
		set_log_tlevel(level, ERROR, "Too many arguments in sprite param.");
		return (FALSE);
	}
	if (ft_str_endwith(splitted[1], ".xpm"))
		return (parse_xpm_empty_texture(level, \
		&level->sprite_empty_texture, splitted[1]));
	else
	{
		set_log_tlevel(level, ERROR, "File don't end with .xpm.");
		return (FALSE);
	}
}
