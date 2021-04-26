/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_empty_texture_struct.h                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:03:30 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 17:22:18 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_EMPTY_TEXTURE_STRUCT_H
# define CUB3D_GAME_EMPTY_TEXTURE_STRUCT_H

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

typedef struct s_empty_texture
{
	t_color	color;
	char	*texture_file_path;
}	t_empty_texture;

/*
**	END DEFINES
*/

#endif
