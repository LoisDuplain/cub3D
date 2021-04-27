/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_plane_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:43:49 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/27 14:44:03 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_plane_texture(t_render_thread *r_thread, t_ray ray,
	t_raycast_result r_result)
{
	if (r_result.plane.px == 1)
		draw_plane_ew_texture(r_thread, r_result, ray);
	else if (r_result.plane.py == 1)
		draw_plane_sn_texture(r_thread, r_result, ray);
	else if (r_result.plane.pz == 1)
		draw_plane_cf_texture(r_thread, r_result, ray);
}
