/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_plane_func.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:45:12 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/08 16:22:06 by lduplain         ###   ########lyon.fr   */
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
**	./game/create_plane.c
*/
t_plane	create_plane(int px, int py, int pz, int dist);

/*
**	Initialize planes.
**	./game/init_planes.c
*/
void	init_planes(t_game *game);

#endif