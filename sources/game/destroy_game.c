/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:13:05 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 18:22:12 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*destroy_game(t_game **game)
{
	int	texture_index;

	if (*game != NULL)
	{
		destroy_level(&(*game)->current_level);
		texture_index = -1;
		while (++texture_index < 7)
			destroy_texture((*game)->window, &(*game)->textures[texture_index]);
		bettermlx_destroy_window(&(*game)->window);
		free((*game)->rays);
		(*game)->rays = NULL;
		free(*game);
		*game = NULL;
	}
	return (NULL);
}
