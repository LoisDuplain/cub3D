/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_current_level.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:54:01 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/06 16:49:28 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_current_level(t_game *game, t_level *level)
{
	if (game->current_level == NULL)
		destroy_level(&game->current_level);
	game->current_level = level;
	init_player(game);
}
