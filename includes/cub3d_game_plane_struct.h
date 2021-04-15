/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_plane_struct.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:59:15 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/15 13:10:45 by lduplain         ###   ########lyon.fr   */
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
	int		px;
	int		py;
	int		pz;
	float	dist;
}	t_plane;

/*
**	END DEFINES
*/

#endif
