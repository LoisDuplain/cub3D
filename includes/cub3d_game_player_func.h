/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_player_func.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:17:24 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/28 17:18:04 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_PLAYER_FUNC_H
# define CUB3D_GAME_PLAYER_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "./cub3d.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Initialize player.
**	./game/player/init_player.c
*/
void	init_player(t_game *game);

/*
**	Rotate player camera. ayaw(add yaw) apitch(add pitch).
**	./game/player/rotate_camera.c
*/
void	rotate_camera(t_game *game, float ayaw, float apitch);

/*
**	Rotate player camera (keyboard).
**	./game/player/rotate_camera_kb.c
*/
void	rotate_camera_kb(t_game *game, long delta, t_bool keyboard[384]);

/*
**	Change player fov.
**	./game/player/change_fov.c
*/
void	change_fov(t_game *game, t_bool keyboard[384]);

/*
**	Changer player render distance.
**	./game/player/change_render_distance.c
*/
void	change_render_distance(t_game *game, t_bool keyboard[384]);

/*
**	Move player.
**	./game/player/change_render_distance.c
*/
void	move_player(t_game *game, float vx, float vy);

/*
**	Move player forwards or backwards.
**	./game/player/move_player_fb.c
*/
void	move_player_fb(t_game *game, long delta, t_bool keyboard[384]);

/*
**	Move player left or right.
**	./game/player/move_player_lr.c
*/
void	move_player_lr(t_game *game, long delta, t_bool keyboard[384]);

/*
**	Check if player collide with sprite or no.
**	./game/player/sprite_collide_player.c
*/
t_bool	sprite_collide_player(t_game *game, float nx, float ny);

#endif
