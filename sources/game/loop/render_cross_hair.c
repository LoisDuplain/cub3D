/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cross_hair.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:49:38 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/27 16:49:46 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_cross_hair(t_game *game)
{
	bettermlx_draw_line(game->window,
		create_vector(
			ceil(game->window->real_width / 2),
			ceil(game->window->real_height / 2) - 5,
			0
			),
		create_vector(
			floor(game->window->real_width / 2),
			floor(game->window->real_height / 2) + 6,
			0
			),
		create_color(0, 255, 255, 255));
	bettermlx_draw_line(game->window,
		create_vector(
			ceil(game->window->real_width / 2) - 5,
			ceil(game->window->real_height / 2),
			0
			),
		create_vector(
			floor(game->window->real_width / 2) + 6,
			floor(game->window->real_height / 2),
			0
			),
		create_color(0, 255, 255, 255));
}
