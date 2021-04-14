/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:36:14 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 18:41:28 by lduplain         ###   ########lyon.fr   */
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
	long long		start_time;
	long long		f_time;

	start_time = bettermlx_get_time();
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
	f_time = 1000 / (bettermlx_get_time() - start_time);
	char fps_text[8] = "FPS: ";
	fps_text[5] = f_time / 10 + 48;
	fps_text[6] = f_time % 10 + 48;
	fps_text[7] = '\0';
	mlx_string_put(game->window->mlx_ptr, game->window->win_ptr, 20, 20, 0x00FFFFFF, fps_text);
	if (game->window->keyboard[KEY_ESCAPE])
		exit_game(&game, OK, "Game exited successfully.");
	update_loop(game, 1, game->window->keyboard);
	return (1);
}
