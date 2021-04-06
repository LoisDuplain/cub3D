/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:51:35 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/06 17:05:40 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_rays(t_game *game)
{
	(void)game;
	game->rays = ft_calloc(game->window->real_width * game->window->real_height, sizeof(t_ray));
}
