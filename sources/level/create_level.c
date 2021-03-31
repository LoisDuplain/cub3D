/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:20:00 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/31 09:07:05 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_level	*create_level(void)
{
	t_level	*level;

	level = ft_calloc(1, sizeof(t_level));
	if (level == NULL)
		return (NULL);
	level->file_content = NULL;
	level->window_width = 0;
	level->window_height = 0;
	level->north_empty_texture = NULL;
	level->south_empty_texture = NULL;
	level->west_empty_texture = NULL;
	level->east_empty_texture = NULL;
	level->sprite_empty_texture = NULL;
	level->floor_empty_texture = NULL;
	level->ceiling_is_skybox = FALSE;
	level->ceiling_empty_texture = NULL;
	level->have_required_params = FALSE;
	level->log_type = NONE;
	level->log_message = NULL;
	return (level);
}
