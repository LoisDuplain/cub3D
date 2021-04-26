/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_level_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:40:09 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 17:24:36 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_LEVEL_STRUCT_H
# define CUB3D_LEVEL_STRUCT_H

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

typedef struct s_level
{
	char			**file_content;
	size_t			params_line_index;
	int				window_width;
	int				window_height;
	t_empty_texture	*empty_textures[7];
	size_t			map_width;
	size_t			map_height;
	char			**map_content;
	t_player		player;
	t_log_type		log_type;
	char			*log_message;
	int				sprites_count;
	t_sprite		*sprites;
}	t_level;

/*
**	END DEFINES
*/

#endif
