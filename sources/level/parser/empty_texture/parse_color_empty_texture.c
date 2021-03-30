/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_empty_texture.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:36:20 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/30 10:41:55 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	parse_color_empty_texture(t_level *level, \
	t_empty_texture **empty_texture, \
	char *color)
{
	char			**splitted;

	*empty_texture = create_empty_texture();
	if (empty_texture == NULL)
	{
		set_log_tlevel(level, ERROR, "empty_texture allocation failed.");
		return (FALSE);
	}
	splitted = ft_split(color, ",");
	if (splitted == NULL)
	{
		set_log_tlevel(level, ERROR, "Color splitting failed.");
		return (FALSE);
	}
	if (ft_get_splitted_size(splitted) != 3)
	{
		ft_destroy_splitted(&splitted);
		set_log_tlevel(level, ERROR, "Wrong number of color argument.");
		return (FALSE);
	}
	if (!parse_splitted_color_in_empty_texture(level, empty_texture, splitted))
		return (FALSE);
	ft_destroy_splitted(&splitted);
	return (TRUE);
}
