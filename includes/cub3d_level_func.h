/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_level_func.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:44:26 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/01 11:15:53 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_LEVEL_FUNC_H
# define CUB3D_LEVEL_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "./cub3d.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Create and malloc level.
**	./level/create_level.c
*/
t_level	*create_level(void);

/*
**	Load a new level by a file located at (char *)level_file_path.
**	./level/load_level_file_content.c
*/
t_level	*load_level(char *level_file_path);

/*
**	Destroy and free level.
**	./level/destroy_level.c
*/
void	*destroy_level(t_level **level);

/*
**	Dipslay level in console.
**	./level/display_level.c
*/
void	display_level(t_level *level);

#endif
