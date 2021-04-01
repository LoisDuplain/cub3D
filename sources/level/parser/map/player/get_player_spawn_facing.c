/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_spawn_facing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:36:30 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/01 15:37:37 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_spawn_facing	get_player_spawn_facing(char c)
{
	if (c == 'N')
		return (NORTH);
	if (c == 'S')
		return (SOUTH);
	if (c == 'W')
		return (WEST);
	return (EAST);
}
