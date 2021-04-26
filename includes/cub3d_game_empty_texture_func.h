/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_empty_texture_func.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:52:14 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 17:22:15 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_EMPTY_TEXTURE_FUNC_H
# define CUB3D_GAME_EMPTY_TEXTURE_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "./cub3d.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Create new empty texture. (allocated)
**	./texture/create_empty_texture.c
*/
t_empty_texture	*create_empty_texture(void);

/*
**	Destroy (t_empty_texture *)texture.
**	./texture/destroy_empty_texture.c
*/
void			*destroy_empty_texture(t_empty_texture **empty_texture);

#endif
