/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:51:35 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/28 13:40:55 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_rays(t_game *game)
{
	int			x;
	int			y;

	if (game->window->real_width * game->window->real_height != game->rays_size)
	{
		game->rays_size = game->window->real_width * game->window->real_height;
		free(game->rays);
		game->rays = NULL;
	}
	if (game->rays == NULL)
		game->rays = ft_calloc(game->rays_size, sizeof(t_ray));
	if (game->rays == NULL)
		exit_game(&game, ERROR, "Rays allocation failed.");
	y = -1;
	while (++y < game->window->real_height)
	{
		x = -1;
		while (++x < game->window->real_width)
		{
			game->rays[y * game->window->real_width + x] = create_ray(
					create_render_vector(game->cur_lvl->player, game->window, x,
						y), x, y);
		}
	}
}
