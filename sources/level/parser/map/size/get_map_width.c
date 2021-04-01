/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:23:06 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/01 11:57:39 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	get_map_width(t_level *level)
{
	size_t	max_width;
	size_t	current_width;
	size_t	line_index;

	max_width = 0;
	current_width = 0;
	line_index = level->params_line_index;
	while (level->file_content[line_index])
	{
		current_width = ft_strlen(level->file_content[line_index]);
		if (current_width > max_width)
			max_width = current_width;
		line_index++;
	}
	return (max_width);
}
