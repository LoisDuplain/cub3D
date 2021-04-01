/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:56:57 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/01 19:20:59 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	create_map_content(t_level *level)
{
	size_t	line_index;

	if (level->map_content != NULL)
		ft_destroy_file_content(&level->map_content);
	level->map_content = ft_calloc(level->map_height + 1, sizeof(char *));
	if (level->map_content == NULL)
	{
		set_log_tlevel(level, ERROR, "Map content allocation failed.");
		return (FALSE);
	}
	line_index = 0;
	while (line_index < level->map_height)
	{
		level->map_content[line_index] = NULL;
		line_index++;
	}
	level->map_content[line_index] = NULL;
	return (TRUE);
}
