/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:35:44 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/05 15:38:43 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_minimap(t_game *game)
{
	int		y;
	int		x;
	int		mx;
	int		my;
	t_color	color;

	y = -1;
	while (++y < game->window->real_height / 4)
	{
		x = -1;
		while (++x < game->window->real_width / 4)
		{
			my = y * game->cur_lvl->map_height * 4 / game->window->real_height;
			mx = x * game->cur_lvl->map_width * 4 / game->window->real_width;
			if (game->cur_lvl->map_content[my][mx] == 0)
				color = create_color(0, 0, 0, 0);
			else if (game->cur_lvl->map_content[my][mx] == 1)
				color = create_color(0, 255, 255, 255);
			else if (game->cur_lvl->map_content[my][mx] == 2)
				color = create_color(0, 0, 255, 0);
			else
				color = create_color(255, 255, 0, 0);
			bettermlx_pixel_put(game->window, create_vector(x, y, 0), color, 1);
		}
	}
}
