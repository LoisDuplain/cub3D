/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:35:42 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/06 15:12:14 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_loop(t_game *game, t_window *window)
{
	(void)game;
	(void)window;
	bettermlx_draw_line(window, create_vector(50, 50, 0), create_vector(500, 300, 0), create_icolor(0, 255, 0, 0));
	bettermlx_draw_line(window, create_vector(500, 300, 0), create_vector(10, 800, 0), create_icolor(0, 0, 255, 0));
	bettermlx_draw_line(window, create_vector(10, 800, 0), create_vector(50, 50, 0), create_icolor(0, 0, 0, 255));
	bettermlx_render(window);
}
