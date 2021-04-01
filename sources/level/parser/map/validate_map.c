/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:55:12 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/01 19:16:39 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	validate_map(t_level *level, int x, int y)
{
	if (x < 0 || x >= (int)level->map_width)
		return (FALSE);
	if (y < 0 || y >= (int)level->map_height)
		return (FALSE);
	if (level->map_content[y][x] == ' ')
		return (FALSE);
	if (level->map_content[y][x] == '1' || level->map_content[y][x] == -1)
		return (TRUE);
	level->map_content[y][x] = -1;
	if (!validate_map(level, x + 1, y))
		return (FALSE);
	if (!validate_map(level, x - 1, y))
		return (FALSE);
	if (!validate_map(level, x, y + 1))
		return (FALSE);
	if (!validate_map(level, x, y - 1))
		return (FALSE);
	return (TRUE);
}
