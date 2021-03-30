/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_splitted_color_in_empty_texture.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 10:26:31 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/30 10:41:44 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	parse_splitted_color_in_empty_texture(t_level *level,
	t_empty_texture **empty_texture,
	char **splitted_color)
{
	int		r;
	int		g;
	int		b;

	r = ft_natoi(splitted_color[0], 3);
	g = ft_natoi(splitted_color[1], 3);
	b = ft_natoi(splitted_color[2], 3);
	if (r < 0 || g < 0 || b < 0)
	{
		ft_destroy_splitted(&splitted_color);
		set_log_tlevel(level, ERROR, \
		"Argument in color can't be negative.");
		return (FALSE);
	}
	if (r > 255 || g > 255 || b > 255)
	{
		ft_destroy_splitted(&splitted_color);
		set_log_tlevel(level, ERROR, \
		"Argument in color can't be greater than 255.");
		return (FALSE);
	}
	(*empty_texture)->color = create_color(0, r, g, b);
	return (TRUE);
}
