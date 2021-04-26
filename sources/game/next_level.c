/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:58:48 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 18:23:03 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	next_level(t_game *game)
{
	t_level	*new_level;

	game->current_level_id++;
	if (game->current_level_id >= game->level_size)
		game->current_level_id = 1;
	new_level = load_level(game->levels_file_path[game->current_level_id]);
	if (new_level == NULL)
	{
		log_message(ERROR, "Level loading failed. (null level)");
		return ;
	}
	if (new_level->log_type != OK)
	{
		log_tlevel(new_level);
		return ;
	}
	destroy_level(&game->current_level);
	int texture_index = -1;
	while (++texture_index < 7)
		destroy_texture(game->window, &game->textures[texture_index]);
	set_current_level(game, new_level);
	init_current_level(game);
}
