/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_render_thread.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:48:35 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 19:51:25 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_render_thread	create_render_thread(t_game *game, int p_start, int p_end)
{
	t_render_thread	render_thread;

	render_thread.game = game;
	render_thread.window = game->window;
	render_thread.lvl = game->cur_lvl;
	render_thread.m_content = game->cur_lvl->map_content;
	render_thread.p_start = p_start;
	render_thread.p_end = p_end;
	return (render_thread);
}
