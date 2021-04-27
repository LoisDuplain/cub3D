/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:15:23 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/27 16:16:00 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_game *game, float vx, float vy)
{
	float	px;
	float	py;
	float	nx;
	float	ny;

	px = game->cur_lvl->player.position.vx;
	py = game->cur_lvl->player.position.vy;
	nx = px + vx;
	ny = py + vy;
	if (!sprite_collide_player(game, nx, py) && game->cur_lvl->map_content[(int)(py)][(int)(nx)] != 1)
		game->cur_lvl->player.position.vx = nx;
	if (!sprite_collide_player(game, px, ny) && game->cur_lvl->map_content[(int)(ny)][(int)(px)] != 1)
		game->cur_lvl->player.position.vy = ny;
}
