/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_required_params.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 09:37:23 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 17:04:05 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	check_required_params(t_level *level)
{
	t_bool	result;
	int		texture_index;

	result = TRUE;
	if (level->window_width == 0 || level->window_height == 0)
		result = FALSE;
	texture_index = -1;
	while (++texture_index < 7)
	{
		if (!level->empty_textures[texture_index])
		{
			result = FALSE;
			break ;
		}
	}
	if (level->log_type == NONE && result)
		set_log_tlevel(level, OK, "All required params stored.");
	else if (level->log_type == NONE && !result)
		set_log_tlevel(level, ERROR, "Missing required params.");
	return (result);
}
