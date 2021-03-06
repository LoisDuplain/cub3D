/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_plane_struct.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:59:15 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/21 12:17:52 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_PLANE_STRUCT_H
# define CUB3D_GAME_PLANE_STRUCT_H

/*
**	START CUSTOM INCLUDES
*/

# include "./cub3d.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	START DEFINES
*/

typedef struct s_plane
{
	float	px;
	float	py;
	float	pz;
	float	dist;
	float	px_dist;
	float	py_dist;
	float	pz_dist;
}	t_plane;

/*
**	END DEFINES
*/

#endif
