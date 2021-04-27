/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_current_level.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:54:01 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 19:51:23 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_current_level(t_game *game, t_level *level)
{
	if (game->cur_lvl == NULL)
		destroy_level(&game->cur_lvl);
	game->cur_lvl = level;
}
