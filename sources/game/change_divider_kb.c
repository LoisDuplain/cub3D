/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_divider_kb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:35:26 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/28 13:35:35 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_divider_kb(t_game *game, t_bool keyboard[384])
{
	if (keyboard[KEY_PAGE_UP])
		game->window->divider *= 2;
	if (keyboard[KEY_PAGE_DOWN])
		game->window->divider /= 2;
	if (game->window->divider < 1)
		game->window->divider = 1;
	if (game->window->divider > 16)
		game->window->divider = 16;
	game->window->real_width = game->window->width / game->window->divider;
	game->window->real_height = game->window->height / game->window->divider;
	init_rays(game);
	update_rays(game);
}
