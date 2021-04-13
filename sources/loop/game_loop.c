/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:36:14 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/13 16:43:06 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_game *game)
{
	t_render_thread	render_threads[THREADS];
	pthread_t		threads[THREADS];
	int				size;
	int				ret;
	int				i;

	size = game->rays_size / THREADS;
	i = -1;
	while (++i < THREADS)
	{
		render_threads[i] = create_render_thread(game, size * i, size * (i + 1));
		ret = pthread_create(&threads[i], NULL, &render_loop, &render_threads[i]);
		if (ret < 0)
			exit_game(&game, ERROR, "Thread creation failed.");
	}
	i = -1;
	while (++i < THREADS)
	{
		ret = pthread_join(threads[i], NULL);
		if (ret < 0)
			exit_game(&game, ERROR, "Thread join failed.");
	}
	bettermlx_render(game->window);
	if (game->window->keyboard[KEY_ESCAPE])
		exit_game(&game, OK, "Game exited successfully.");
	update_loop(game, 1, game->window->keyboard);
	return (1);
}
