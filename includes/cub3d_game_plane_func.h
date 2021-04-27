/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_plane_func.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:45:12 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/27 14:46:13 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_PLANE_FUNC_H
# define CUB3D_GAME_PLANE_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "./cub3d.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Create new plane.
**	./game/plane/create_plane.c
*/
t_plane		create_plane(int px, int py, int pz, int dist);

/*
**	Initialize planes.
**	./game/plane/init_planes.c
*/
void		init_planes(t_game *game);

/*
**	Update x planes.
**	./game/plane/update_x_planes.c
*/
void		update_x_planes(t_level *level);

/*
**	Update y planes.
**	./game/plane/update_y_planes.c
*/
void		update_y_planes(t_level *level);

/*
**	Update z planes.
**	./game/plane/update_z_planes.c
*/
void		update_z_planes(t_level *level);

/*
**	Check intersection with x plane.
**	./game/plane/x/intrsct_x_plane.c
*/
t_bool		intrsct_x_plane(t_raycast_result *r_result, t_level *level,
				t_plane plane);

/*
**	For all x positive planes.
**	./game/plane/x/get_x_pos_planes.c
*/
void		get_x_pos_planes(t_raycast_result *r_result, t_level *level);

/*
**	For all x negative planes.
**	./game/plane/x/get_x_neg_planes.c
*/
void		get_x_neg_planes(t_raycast_result *r_result, t_level *level);

/*
**	Check intersection with y plane.
**	./game/plane/y/intrsct_y_plane.c
*/
t_bool		intrsct_y_plane(t_raycast_result *r_result, t_level *level,
				t_plane plane);

/*
**	For all y positive planes.
**	./game/plane/y/get_y_pos_planes.c
*/
void		get_y_pos_planes(t_raycast_result *r_result, t_level *level);

/*
**	For all y negative planes.
**	./game/plane/y/get_y_neg_planes.c
*/
void		get_y_neg_planes(t_raycast_result *r_result, t_level *level);

/*
**	For all z positive planes.
**	./game/plane/z/get_z_pos_planes.c
*/
void		get_z_pos_planes(t_raycast_result *r_result, t_level *level);

/*
**	For all z negative planes.
**	./game/plane/z/get_z_neg_planes.c
*/
void		get_z_neg_planes(t_raycast_result *r_result, t_level *level);

/*
**	For all planes.
**	./game/plane/get_planes.c
*/
void		get_planes(t_render_thread *r_thread, t_ray ray,
				t_raycast_result *r_result);

/*
**	Get plane intersection point.
**	./game/plane/get_plane_intrsct_point.c
*/
t_vector3	get_plane_intrsct_point(t_vector3 p_loc, t_vector3 r_dir,
				t_plane plane, float distance);

/*
**	Check if intersection point is in world or no.
**	./game/plane/is_in_world.c
*/
t_bool		is_in_world(t_level *level, t_vector3 intrsct);

/*
**	Check if intersection point is in world or no.
**	./game/plane/draw_plane_texture.c
*/
void		draw_plane_texture(t_render_thread *r_thread, t_ray ray,
				t_raycast_result r_result);

#endif