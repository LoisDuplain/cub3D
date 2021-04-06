/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_register_loop.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:00:42 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/02 14:05:33 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bettermlx_register_loop(t_window *window,
	void *param, int (*funct_ptr)())
{
	mlx_loop_hook(window->mlx_ptr, funct_ptr, param);
	mlx_loop(window->mlx_ptr);
}
