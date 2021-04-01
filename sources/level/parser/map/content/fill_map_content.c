/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:39:41 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/01 19:10:15 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	fill_map_content(t_level *level)
{
	size_t	map_content_index;
	size_t	line_index;
	char	*dup_str;

	map_content_index = 0;
	line_index = level->params_line_index;
	while (level->file_content[line_index])
	{
		dup_str = ft_strndup(level->file_content[line_index],
				level->map_width, FALSE);
		if (dup_str == NULL)
		{
			set_log_tlevel(level, ERROR, "(fill_map_content) alloc failed");
			return (FALSE);
		}
		level->map_content[map_content_index] = dup_str;
		line_index++;
		map_content_index++;
	}
	level->map_content[map_content_index] = NULL;
	return (TRUE);
}
