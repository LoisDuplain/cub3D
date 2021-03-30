/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:40:29 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/30 09:56:07 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_game(char *level_file_path, t_bool screenshot)
{
	t_game	*game;

	(void)screenshot;
	game = create_game();
	game->current_level = load_level(level_file_path);
	if (game->current_level->log_type != OK)
		exit_game(&game, game->current_level->log_type, game->current_level->log_message);
	display_level(game->current_level);
	log_tlevel(game->current_level);
	exit_game(&game, OK, "Game exited successfully.");
}
