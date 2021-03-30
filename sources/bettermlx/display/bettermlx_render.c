/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:36:49 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/25 11:45:55 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bettermlx_render(t_window *window)
{
	mlx_put_image_to_window(window->mlx_ptr, \
	window->win_ptr, \
	window->image->img_ptr, \
	0, \
	0);
}
