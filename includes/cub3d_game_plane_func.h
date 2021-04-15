/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_plane_func.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:45:12 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/15 20:47:19 by lduplain         ###   ########.fr       */
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

#endif