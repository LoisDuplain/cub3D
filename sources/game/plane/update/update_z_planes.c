/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_z_planes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:10:38 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/15 20:12:48 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_z_planes(t_world *world)
{
	world->z_planes[0].pz_dist = -world->player.location.vz;
	world->z_planes[1].pz_dist = world->z_planes[1].dist
		- world->player.location.vz;
}
