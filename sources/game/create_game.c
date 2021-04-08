/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:07:14 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/08 16:20:26 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*create_game(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (game == NULL)
		exit_game(&game, ERROR, "(t_game *)game allocation failed.");
	game->current_level = NULL;
	game->window = NULL;
	game->world.x_planes = NULL;
	game->world.y_planes = NULL;
	game->rays = NULL;
	return (game);
}
