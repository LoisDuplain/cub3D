/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_empty_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 10:46:06 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/30 10:53:05 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	parse_empty_texture(t_level *level,
	t_empty_texture **empty_texture,
	char *argument)
{
	if (ft_str_endwith(argument, ".xpm"))
		return (parse_xpm_empty_texture(level, \
		empty_texture, \
		argument));
	else
		return (parse_color_empty_texture(level, \
		empty_texture, \
		argument));
}
