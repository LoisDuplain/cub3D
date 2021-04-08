/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:51:35 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/08 16:32:18 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_rays(t_game *game)
{
	int			r_width;
	int			r_height;
	int			x;
	int			y;
	int			ray_index;
	t_vector3	direction;

	r_width = game->window->real_width;
	r_height = game->window->real_height;
	game->rays_size = r_width * r_height;
	game->rays = ft_calloc(game->rays_size, sizeof(t_ray));
	if (game->rays == NULL)
		exit_game(&game, ERROR, "Rays allocation failed");
	ray_index = 0;
	y = -1;
	while (++y < r_height)
	{
		x = -1;
		while (++x < r_width)
		{
			direction = create_vector(2 * tan(game->world.player.fov_x * RADIAN * 0.5) / r_width * (x - r_width * 0.5),
									-1,
									-2 * tan(game->world.player.fov_y * RADIAN * 0.5) / r_height * (y - r_height * 0.5));
			game->rays[ray_index] = create_ray(direction, x, y);
			ray_index++;
		}
	}
}
