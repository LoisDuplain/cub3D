/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:54:07 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/25 11:46:03 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bettermlx_hook(
	t_window *window,
	t_x11event x11event,
	int (*funct)(),
	void *param)
{
	mlx_hook(window->win_ptr, x11event, 0, funct, param);
}
