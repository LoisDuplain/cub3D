/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_planes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:55:43 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 19:06:47 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_planes(t_game *game)
{
	int		x_index;
	int		y_index;

	game->world.x_planes_size = (int)game->current_level->map_width - 1;
	game->world.y_planes_size = (int)game->current_level->map_height - 1;
	game->world.z_planes_size = 2;
	game->world.x_planes = ft_calloc(game->world.x_planes_size,
			sizeof(t_plane));
	if (game->world.x_planes == NULL)
		exit_game(&game, ERROR, "x_planes allocation failed.");
	game->world.y_planes = ft_calloc(game->world.y_planes_size,
			sizeof(t_plane));
	if (game->world.y_planes == NULL)
		exit_game(&game, ERROR, "y_planes allocation failed.");
	game->world.z_planes = ft_calloc(2, sizeof(t_plane));
	if (game->world.z_planes == NULL)
		exit_game(&game, ERROR, "z_planes allocation failed.");
	x_index = -1;
	while (++x_index < game->world.x_planes_size)
		game->world.x_planes[x_index] = create_plane(1, 0, 0, x_index + 1);
	y_index = -1;
	while (++y_index < game->world.y_planes_size)
		game->world.y_planes[y_index] = create_plane(0, 1, 0, y_index + 1);
	game->world.z_planes[0] = create_plane(0, 0, 1, 0);
	game->world.z_planes[1] = create_plane(0, 0, 1, 1);
}
