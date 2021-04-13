/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_render_threah_struct.h                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:26:03 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/13 15:30:57 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_RENDER_THREAD_STRUCT_H
# define CUB3D_GAME_RENDER_THREAD_STRUCT_H

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

typedef struct s_render_thread
{
	t_game		*game;
	t_window	*window;
	t_world		world;
	char		**m_content;
	int			p_start;
	int			p_end;
}	t_render_thread;

/*
**	END DEFINES
*/

#endif
