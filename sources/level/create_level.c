/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:20:00 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 17:01:12 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_level	*create_level(void)
{
	t_level	*level;
	int		texture_index;

	level = ft_calloc(1, sizeof(t_level));
	if (level == NULL)
		return (NULL);
	level->file_content = NULL;
	level->params_line_index = 0;
	level->window_width = 0;
	level->window_height = 0;
	texture_index = -1;
	while (++texture_index < 7)
		level->empty_textures[texture_index] = NULL;
	level->ceiling_is_skybox = FALSE;
	level->map_width = 0;
	level->map_height = 0;
	level->map_content = NULL;
	level->log_type = NONE;
	level->log_message = NULL;
	return (level);
}
