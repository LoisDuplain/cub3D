/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_z_planes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:10:38 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 18:44:49 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_z_planes(t_level *level)
{
	level->z_planes[0].pz_dist = -level->player.position.vz;
	level->z_planes[1].pz_dist = level->z_planes[1].dist
		- level->player.position.vz;
}
