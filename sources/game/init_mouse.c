/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:10:55 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/28 13:11:28 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mouse(t_game *game)
{
	mlx_hook(game->window->win_ptr, MOTION_NOTIFY, 1L << 6,
		&mouse_move_hook, game);
	mlx_mouse_hide();
	mlx_mouse_move(game->window->win_ptr, game->window->width * 0.5,
		game->window->height * 0.5);
}
