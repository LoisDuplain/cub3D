/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_texture_struct.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:24:38 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 17:04:33 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_TEXTURE_STRUCT_H
# define CUB3D_GAME_TEXTURE_STRUCT_H

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

typedef enum e_texture_id
{
	NORTH_TEXTURE = 0,
	SOUTH_TEXTURE = 1,
	WEST_TEXTURE = 2,
	EAST_TEXTURE = 3,
	SPRITE_TEXTURE = 4,
	FLOOR_TEXTURE = 5,
	CEILING_TEXTURE = 6,
}	t_texture_id;

typedef struct s_texture
{
	t_color		color;
	t_image		*image;
}	t_texture;

/*
**	END DEFINES
*/

#endif
