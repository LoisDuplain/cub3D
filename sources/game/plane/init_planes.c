/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_planes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:55:43 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 19:51:25 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_planes(t_game *game)
{
	int		x_index;
	int		y_index;

	game->cur_lvl->x_planes_size = (int)game->cur_lvl->map_width - 1;
	game->cur_lvl->y_planes_size = (int)game->cur_lvl->map_height - 1;
	game->cur_lvl->z_planes_size = 2;
	game->cur_lvl->x_planes = ft_calloc(game->cur_lvl->x_planes_size,
			sizeof(t_plane));
	if (game->cur_lvl->x_planes == NULL)
		exit_game(&game, ERROR, "x_planes allocation failed.");
	game->cur_lvl->y_planes = ft_calloc(game->cur_lvl->y_planes_size,
			sizeof(t_plane));
	if (game->cur_lvl->y_planes == NULL)
		exit_game(&game, ERROR, "y_planes allocation failed.");
	game->cur_lvl->z_planes = ft_calloc(2, sizeof(t_plane));
	if (game->cur_lvl->z_planes == NULL)
		exit_game(&game, ERROR, "z_planes allocation failed.");
	x_index = -1;
	while (++x_index < game->cur_lvl->x_planes_size)
		game->cur_lvl->x_planes[x_index] = create_plane(1, 0, 0, x_index + 1);
	y_index = -1;
	while (++y_index < game->cur_lvl->y_planes_size)
		game->cur_lvl->y_planes[y_index] = create_plane(0, 1, 0, y_index + 1);
	game->cur_lvl->z_planes[0] = create_plane(0, 0, 1, 0);
	game->cur_lvl->z_planes[1] = create_plane(0, 0, 1, 1);
}
