/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:34:36 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/08 15:11:46 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_plane	create_plane(int px, int py, int pz, int dist)
{
	t_plane	plane;

	plane.px = px;
	plane.py = py;
	plane.pz = pz;
	plane.dist = dist;
	return (plane);
}
