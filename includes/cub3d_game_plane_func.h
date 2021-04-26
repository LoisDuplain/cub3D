/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_plane_func.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:45:12 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 16:55:08 by lduplain         ###   ########lyon.fr   */
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
t_plane	create_plane(int px, int py, int pz, int dist);

/*
**	Initialize planes.
**	./game/plane/init_planes.c
*/
void	init_planes(t_game *game);

/*
**	Update x planes.
**	./game/plane/update_x_planes.c
*/
void	update_x_planes(t_world *world);

/*
**	Update y planes.
**	./game/plane/update_y_planes.c
*/
void	update_y_planes(t_world *world);

/*
**	Update z planes.
**	./game/plane/update_z_planes.c
*/
void	update_z_planes(t_world *world);

/*
**	Check intersection with x plane.
**	./loop/render/x/intrsct_x_plane.c
*/
t_bool		intrsct_x_plane(t_raycast_result *r_result, t_world world,
				char **map_content, t_plane plane);

/*
**	For all x positive planes.
**	./loop/render/x/get_x_pos_planes.c
*/
void		get_x_pos_planes(t_raycast_result *r_result, t_world world,
				char **map_content);

/*
**	For all x negative planes.
**	./loop/render/x/get_x_neg_planes.c
*/
void		get_x_neg_planes(t_raycast_result *r_result, t_world world,
				char **map_content);

/*
**	Check intersection with y plane.
**	./loop/render/y/intrsct_y_plane.c
*/
t_bool		intrsct_y_plane(t_raycast_result *r_result, t_world world,
				char **map_content, t_plane plane);

/*
**	For all y positive planes.
**	./loop/render/y/get_y_pos_planes.c
*/
void		get_y_pos_planes(t_raycast_result *r_result, t_world world,
				char **map_content);

/*
**	For all y negative planes.
**	./loop/render/y/get_y_neg_planes.c
*/
void		get_y_neg_planes(t_raycast_result *r_result, t_world world,
				char **map_content);

/*
**	For all z positive planes.
**	./loop/render/z/get_z_pos_planes.c
*/
void		get_z_pos_planes(t_raycast_result *r_result, t_world world);

/*
**	For all z negative planes.
**	./loop/render/z/get_z_neg_planes.c
*/
void		get_z_neg_planes(t_raycast_result *r_result, t_world world);

/*
**	Get plane intersection point.
**	./loop/render/get_plane_intrsct_point.c
*/
t_vector3	get_plane_intrsct_point(t_vector3 p_loc, t_vector3 r_dir, t_plane plane,
				float distance);

/*
**	Check if intersection point is in world or no.
**	./loop/render/is_in_world.c
*/
t_bool		is_in_world(t_world world, t_vector3 intrsct);

#endif