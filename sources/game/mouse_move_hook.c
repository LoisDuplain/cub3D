/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:08:35 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/28 13:15:40 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_move_hook(int x, int y, t_game *game)
{
	int	mx;
	int	my;

	mx = x - game->window->width * 0.5;
	my = y - game->window->height * 0.5;
	rotate_camera(game, mx * ROTATION_SPEED, my * ROTATION_SPEED);
	mlx_mouse_move(game->window->win_ptr,
		game->window->width * 0.5,
		game->window->height * 0.5);
	return (0);
}
