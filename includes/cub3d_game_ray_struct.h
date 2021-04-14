/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_ray_struct.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:18:07 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 16:23:03 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_RAY_STRUCT_H
# define CUB3D_GAME_RAY_STRUCT_H

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

typedef struct s_ray
{
	t_vector3	direction;
	t_vector3	pixel;
}	t_ray;

typedef struct s_raycast_result
{
	t_vector3	p_loc;
	t_vector3	r_dir;
	float		distance;
	t_plane		plane;
	t_vector3	intrsct;
}	t_raycast_result;

/*
**	END DEFINES
*/

#endif
