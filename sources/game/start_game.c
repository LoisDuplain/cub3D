/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:40:29 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/28 13:11:48 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_game(char **argv, int level_size, t_bool screenshot)
{
	t_game	*game;
	t_level	*level;

	(void)screenshot;
	game = create_game();
	game->levels_file_path = argv;
	game->level_size = level_size;
	level = load_level(argv[game->current_level_id]);
	if (level == NULL)
		exit_game(&game, ERROR, "First level loading failed.");
	set_current_level(game, level);
	if (level->log_type != OK)
		exit_game(&game, level->log_type, level->log_message);
	game->window = bettermlx_init_window("cub3d - Lois Duplain",
			level->window_width, level->window_height, DIVIDER);
	if (game->window == NULL)
		exit_game(&game, ERROR, "Window creation failed.");
	init_mouse(game);
	init_current_level(game);
	bettermlx_register_loop(game->window, game, game_loop);
}
