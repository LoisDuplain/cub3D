/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_func.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:41:16 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 18:08:18 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_FUNC_H
# define CUB3D_GAME_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "./cub3d.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Create a new game structure.
**	./game/create_game.c
*/
t_game	*create_game(void);

/*
**	Destory and free game structure.
**	./game/destroy_game.c
*/
void	*destroy_game(t_game **game);

/*
**	Start the game with a map file path char **argv[0] and if a screenshot
**	is needed or no.
**	./game/start_game.c
*/
void	start_game(char **argv, int level_size, t_bool screenshot);

/*
**	Exit game correctly with message char *message.
**	./game/exit_game.c
*/
void	exit_game(t_game **game, t_log_type log_type, char *message);

/*
**	Set current level in game.
**	./game/set_current_level.c
*/
void	set_current_level(t_game *game, t_level *level);

/*
**	Initialize current level.
**	./game/init_current_level.c
*/
void	init_current_level(t_game *game);

/*
**	Initialize current level.
**	./game/init_current_level.c
*/
void	next_level(t_game *game);

#endif
