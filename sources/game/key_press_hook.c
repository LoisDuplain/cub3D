/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:03:34 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/28 17:38:07 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press_hook(int key_code, t_game *game)
{
	t_bool	*keyboard;

	game->window->keyboard[key_code] = TRUE;
	keyboard = game->window->keyboard;
	if (keyboard[KEY_PLUS] || keyboard[KEY_MINUS])
		change_fov(game, keyboard);
	change_level(game, keyboard);
	if (keyboard[KEY_PAGE_UP] || keyboard[KEY_PAGE_DOWN])
		change_divider_kb(game, keyboard);
	if (keyboard[KEY_F2])
		bettermlx_screenshot(game->window->image, "screenshot.bmp");
	return (0);
}
