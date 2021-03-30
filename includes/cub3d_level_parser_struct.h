/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_level_parser_struct.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:10:26 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/23 14:34:54 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_LEVEL_PARSER_STRUCT_H
# define CUB3D_LEVEL_PARSER_STRUCT_H

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

typedef enum e_param_type
{
	UNKNOWN = -1,
	RESOLUTION_PARAM = 0,
	NORTH_PARAM = 1,
	SOUTH_PARAM = 2,
	WEST_PARAM = 3,
	EAST_PARAM = 4,
	SPRITE_PARAM = 5,
	FLOOR_PARAM = 6,
	CEILING_PARAM = 7,
}	t_param_type;

/*
**	END DEFINES
*/

#endif