/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_ray_func.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:21:22 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/08 15:48:35 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_RAY_FUNC_H
# define CUB3D_GAME_RAY_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "./cub3d.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Create new ray.
**	./game/create_ray.c
*/
t_ray	create_ray(t_vector3 direction, int x, int y);

/*
**	Initialize rays.
**	./game/create_ray.c
*/
void	init_rays(t_game *game);


#endif
