/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:22:08 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/27 16:22:21 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_level(t_game *game, t_bool keyboard[384])
{
	if (keyboard[KEY_GREATER])
		next_level(game);
	if (keyboard[KEY_LESS])
		previous_level(game);
}
