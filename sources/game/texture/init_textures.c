/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:49:37 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 17:24:52 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_game *game)
{
	int	texture_index;

	texture_index = -1;
	while (++texture_index < 7)
	{
		game->textures[texture_index] = create_texture(game->window, game->current_level->empty_textures[texture_index]);
		if (game->textures[texture_index] == NULL)
			exit_game(&game, ERROR, "Texture initialization failed.");
	}
}
