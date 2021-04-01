/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player_struch.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:01:02 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/01 15:09:18 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PLAYER_STRUCT_H
# define CUB3D_PLAYER_STRUCT_H

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

typedef enum e_spawn_facing
{
	NORTH = 0,
	EAST = 90,
	SOUTH = 180,
	WEST = 270,
}	t_spawn_facing;

typedef struct s_player
{
	t_vector3		location;
	float			yaw;
	float			pitch;
	t_spawn_facing	spawn_facing;
}	t_player;

/*
**	END DEFINES
*/

#endif