/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_player_struct.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:01:02 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/16 10:58:44 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_PLAYER_STRUCT_H
# define CUB3D_GAME_PLAYER_STRUCT_H

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

typedef struct s_player
{
	t_vector3	location;
	float		yaw;
	float		pitch;
	float		fov_x;
	float		fov_y;
	float		render_distance;
}	t_player;

/*
**	END DEFINES
*/

#endif