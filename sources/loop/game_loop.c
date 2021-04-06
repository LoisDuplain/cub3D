/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:36:14 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/06 14:04:59 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_game *game)
{
	render_loop(game, game->window);
	update_loop(game, 1, game->window->keyboard);
	if (game->window->keyboard[KEY_A])
		puts("a");
	if (game->window->keyboard[KEY_ESCAPE])
		exit_game(&game, OK, "Game exited successfully.");
	return (1);
}
