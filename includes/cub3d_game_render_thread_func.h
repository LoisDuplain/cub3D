/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_render_thread_func.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:05:38 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/13 16:09:33 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_RENDER_THREAD_FUNC_H
# define CUB3D_GAME_RENDER_THREAD_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "./cub3d.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Create a new render thread.
**	./game/render_thread/create_render_thread.c
*/
t_render_thread	create_render_thread(t_game *game, int p_start, int p_end);

#endif
