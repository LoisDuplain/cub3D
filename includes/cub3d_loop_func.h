/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_loop_func.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:36:50 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 17:39:44 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_LOOP_FUNC_H
# define CUB3D_LOOP_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "./cub3d.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	The main game loop who runs render_loop and update_loop.
**	./loop/game_loop.c
*/
int			game_loop(t_game *game);

/*
**	The render loop.
**	./loop/render_loop.c
*/
void		*render_loop(void *r_thread);

/*
**	Check if intersection point is in world or no.
**	./loop/render/is_in_world.c
*/
t_bool		is_in_world(t_vector3 intrsct, t_world world);

/*
**	Get intersection point.
**	./loop/render/get_intrsct_point.c
*/
t_vector3	get_intrsct_point(t_vector3 p_loc, t_vector3 r_dir, t_plane plane, float distance);

/*
**	Check intersection with x plane.
**	./loop/render/x/intrsct_x_plane.c
*/
t_bool 		intrsct_x_plane(t_raycast_result *r_result, t_world world, char **map_content, t_plane plane);

/*
**	For all x positive planes.
**	./loop/render/x/get_x_pos_planes.c
*/
void		get_x_pos_planes(t_raycast_result *r_result, t_world world, char **map_content);

/*
**	For all x negative planes.
**	./loop/render/x/get_x_neg_planes.c
*/
void		get_x_neg_planes(t_raycast_result *r_result, t_world world, char **map_content);

/*
**	Check intersection with y plane.
**	./loop/render/y/intrsct_y_plane.c
*/
t_bool		intrsct_y_plane(t_raycast_result *r_result, t_world world, char **map_content, t_plane plane);

/*
**	For all y positive planes.
**	./loop/render/y/get_y_pos_planes.c
*/
void		get_y_pos_planes(t_raycast_result *r_result, t_world world, char **map_content);

/*
**	For all y negative planes.
**	./loop/render/y/get_y_neg_planes.c
*/
void		get_y_neg_planes(t_raycast_result *r_result, t_world world, char **map_content);

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
**	The update loop.
**	./loop/update_loop.c
*/
void		update_loop(t_game *game, long delta, t_bool keyboard[384]);

#endif
