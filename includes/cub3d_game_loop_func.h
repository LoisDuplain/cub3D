/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_loop_func.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:36:50 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/27 14:40:58 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_LOOP_FUNC_H
# define CUB3D_GAME_LOOP_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "./cub3d.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	The main game loop who runs render_loop and update_loop.
**	./loop/game_loop.c
*/
int			game_loop(t_game *game);

/*
**	The render loop.
**	./loop/render_loop.c
*/
void		*render_loop(void *r_thread);

/*
**	The update loop.
**	./loop/update_loop.c
*/
void		update_loop(t_game *game, long delta, t_bool keyboard[384]);

#endif
