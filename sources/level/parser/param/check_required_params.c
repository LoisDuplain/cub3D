/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_required_params.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 09:37:23 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/31 09:41:08 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	check_required_params(t_level *level)
{
	if (level->window_width == 0 || level->window_height == 0)
		return (FALSE);
	if (!level->north_empty_texture || !level->south_empty_texture)
		return (FALSE);
	if (!level->west_empty_texture || !level->east_empty_texture)
		return (FALSE);
	if (!level->sprite_empty_texture || !level->floor_empty_texture)
		return (FALSE);
	if (!level->ceiling_empty_texture)
		return (FALSE);
	return (TRUE);
}
