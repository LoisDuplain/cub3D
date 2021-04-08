/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:40:29 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/08 16:25:05 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_game(char *level_file_path, t_bool screenshot)
{
	t_game	*game;
	t_level	*level;

	(void)screenshot;
	game = create_game();
	level = load_level(level_file_path);
	if (level == NULL)
		exit_game(&game, ERROR, "First level loading failed.");
	set_current_level(game, level);
	if (level->log_type != OK)
		exit_game(&game, level->log_type, level->log_message);
	game->window = bettermlx_init_window("Cub3d - Lois Duplain",
			level->window_width, level->window_height, 1);
	if (game->window == NULL)
		exit_game(&game, ERROR, "Window creation failed.");
	init_player(game);
	init_rays(game);
	init_planes(game);
	bettermlx_register_loop(game->window, game, game_loop);
}
