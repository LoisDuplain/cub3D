/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player_struct.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:01:02 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/06 16:41:27 by lduplain         ###   ########lyon.fr   */
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

typedef struct s_player
{
	t_vector3		location;
	float			yaw;
	float			pitch;
	int				fov_x;
	int				fov_y;
}	t_player;

/*
**	END DEFINES
*/

#endif