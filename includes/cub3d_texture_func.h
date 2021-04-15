/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_texture_func.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:19:13 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/15 11:59:28 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TEXTURE_FUNC_H
# define CUB3D_TEXTURE_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "./cub3d.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Create new texture. (allocated)
**	./texture/create_texture.c
*/
t_texture	*create_texture(t_window *window, t_empty_texture *empty_texture);

/*
**	Destroy (t_texture *)texture created in window (t_window *)window.
**	./texture/destroy_texture.c
*/
void		*destroy_texture(t_window *window, t_texture **texture);

/*
**	Get color contained in (t_texture *)texture at pixel ((float)perc(percentage)_x, (float)perc(percentage)_y).
**	If ((t_texture *)texture)->image is NULL, function
**	return ((t_texture *)texture)->color.
**	If (t_texture *)texture is NULL, function return black transparent color.
**	./texture/get_texture_color.c
*/
t_color		get_texture_color(t_texture *texture, float perc_x, float perc_y);

#endif
