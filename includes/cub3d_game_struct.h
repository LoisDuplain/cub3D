/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:04:13 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 16:54:11 by lduplain         ###   ########lyon.fr   */
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

typedef struct s_world
{
	t_player	player;
	t_plane		*x_planes;
	t_plane		*y_planes;
	t_plane		*z_planes;
	int			x_planes_size;
	int			y_planes_size;
	int			z_planes_size;
}	t_world;

typedef struct s_game
{
	t_level		*current_level;
	t_window	*window;
	t_world		world;
	t_ray		*rays;
	int			rays_size;
	t_texture	*textures[7];
}	t_game;

/*
**	END DEFINES
*/

#endif
