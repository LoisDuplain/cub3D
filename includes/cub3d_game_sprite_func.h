/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_sprite_func.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:26:29 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 16:40:21 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_SPRITE_FUNC_H
# define CUB3D_GAME_SPRITE_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "./cub3d.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Update sprites.
**	./game/sprite/update_sprites.c
*/
void		update_sprites(t_game *game);

/*
**	Get sprite distance from ray ray.
**	./game/sprite/get_sprite_distance.c
*/
float		get_sprite_distance(t_sprite sprite, t_ray ray, t_player player);

/*
**	Get sprite intersect point.
**	./game/sprite/get_sprite_intrsct_point.c
*/
t_vector3	get_sprite_intrsct_point(t_player player, t_ray ray,
	float distance);

/*
**	Get sprite ratio.
**	./game/sprite/get_sprite_ratio.c
*/
float		get_sprite_ratio(t_vector3 intrsct, t_sprite sprite,
	t_player player);

/*
**	Get sprite texture color.
**	./game/sprite/get_sprite_texture_color.c
*/
t_color		get_sprite_texture_color(t_render_thread *r_thread, t_vector3 intrsct,
	float ratio);

/*
**	Draw sprite.
**	./game/sprite/draw_sprite.c
*/
void	draw_sprite(t_render_thread *r_thread, t_raycast_result *r_result,
	t_ray ray, t_sprite sprite);

/*
**	Draw sprites.
**	./game/sprite/draw_sprites.c
*/
void	draw_sprites(t_render_thread *r_thread, t_raycast_result *r_result,
	t_ray ray);

#endif
