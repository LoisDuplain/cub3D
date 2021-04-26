/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_texture_func.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:27:58 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 17:18:26 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_TEXTURE_FUNC_H
# define CUB3D_GAME_TEXTURE_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "./cub3d.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Create new texture. (allocated)
**	./game/texture/create_texture.c
*/
t_texture	*create_texture(t_window *window, t_empty_texture *empty_texture);

/*
**	Destroy (t_texture *)texture created in window (t_window *)window.
**	./game/texture/destroy_texture.c
*/
void		*destroy_texture(t_window *window, t_texture **texture);

/*
**	Get color contained in (t_texture *)texture at pixel
**	((float)perc(percentage)_x, (float)perc(percentage)_y).
**	If ((t_texture *)texture)->image is NULL, function
**	return ((t_texture *)texture)->color.
**	If (t_texture *)texture is NULL, function return black color.
**	./game/texture/get_texture_color.c
*/
t_color		get_texture_color(t_texture *texture, float perc_x, float perc_y);

/*
**	Initialize textures.
**	./game/texture/init_textures.c
*/
void		init_textures(t_game *game);

/*
**	Draw east or west texture.
**	./game/texture/draw_plane_ew_texture.c
*/
void		draw_plane_ew_texture(t_render_thread *r_thread,
				t_raycast_result r_result, t_ray ray);

/*
**	Draw south or north texture.
**	./game/texture/draw_plane_sn_texture.c
*/
void		draw_plane_sn_texture(t_render_thread *r_thread,
				t_raycast_result r_result, t_ray ray);

/*
**	Draw ceiling or floor texture.
**	./game/texture/draw_plane_cf_texture.c
*/
void		draw_plane_cf_texture(t_render_thread *r_thread,
				t_raycast_result r_result, t_ray ray);

#endif
