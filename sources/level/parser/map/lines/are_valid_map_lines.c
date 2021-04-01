/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_valid_map_lines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:20:56 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/31 17:24:01 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	are_valid_map_lines(t_level *level)
{
	size_t	line_index;
	size_t	char_index;

	line_index = level->params_line_index;
	while (level->file_content[line_index])
	{
		char_index = 0;
		while (level->file_content[line_index][char_index])
		{
			if (!is_valid_map_char(level->file_content[line_index][char_index]))
				return (FALSE);
			char_index++;
		}
		line_index++;
	}
	return (TRUE);
}
