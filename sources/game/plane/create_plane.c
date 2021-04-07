/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:34:36 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/07 08:12:56 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_plane	create_plane(int wx, int wy, int wz, int distance)
{
	t_plane	plane;

	plane.wx = wx;
	plane.wy = wy;
	plane.wz = wz;
	plane.distance = distance;
	return (plane);
}
