/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:04:13 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/28 14:01:08 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_STRUCT_H
# define CUB3D_GAME_STRUCT_H

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

typedef struct s_game
{
	int			level_size;
	int			current_level_id;
	char		**levels_file_path;
	t_level		*cur_lvl;
	t_window	*window;
	t_ray		*rays;
	int			rays_size;
	t_texture	*textures[7];
	t_bool		screenshot;
}	t_game;

/*
**	END DEFINES
*/

#endif
