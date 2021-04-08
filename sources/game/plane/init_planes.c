/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_planes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:55:43 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/08 16:26:45 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_planes(t_game *game)
{
	t_plane	*x_planes;
	t_plane	*y_planes;
	int		x_index;
	int		y_index;

	game->world.x_planes_size = (int)game->current_level->map_width + 1;
	game->world.y_planes_size = (int)game->current_level->map_height + 1;
	x_planes = ft_calloc(game->world.x_planes_size , sizeof(t_plane));
	if (x_planes == NULL)
		exit_game(&game, ERROR, "x_planes allocation failed.");
	y_planes = ft_calloc(game->world.y_planes_size, sizeof(t_plane));
	if (y_planes == NULL)
		exit_game(&game, ERROR, "y_planes allocation failed.");
	x_index = -1;
	while (++x_index < game->world.x_planes_size )
		x_planes[x_index] = create_plane(1, 0, 0, x_index);
	game->world.x_planes = x_planes;
	y_index = -1;
	while (++y_index < game->world.y_planes_size)
		y_planes[y_index] = create_plane(0, 1, 0, y_index);
	game->world.y_planes = y_planes;
}
