/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:56:41 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/20 12:01:12 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	parse_sprites(t_level *level)
{
	level->sprites_count = count_sprites(level);
	level->sprites = ft_calloc(level->sprites_count, sizeof(t_sprite));
	if (level->sprites == NULL)
	{
		set_log_tlevel(level, ERROR, "Sprites allocation failed.");
		return (FALSE);
	}
	
	return (TRUE);
}
