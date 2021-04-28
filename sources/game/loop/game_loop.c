/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:36:14 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/28 17:44:17 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_game *game, long long current_time)
{
	t_render_thread	render_threads[THREADS];
	pthread_t		threads[THREADS];
	int				pixels_per_thread;
	int				thread_index;

	game->last_render_time = current_time;
	pixels_per_thread = game->rays_size / THREADS;
	thread_index = -1;
	while (++thread_index < THREADS)
	{
		render_threads[thread_index] = create_render_thread(game,
				pixels_per_thread * thread_index,
				pixels_per_thread * (thread_index + 1));
		pthread_create(&threads[thread_index], NULL, &render_loop,
			&render_threads[thread_index]);
	}
	thread_index = -1;
	while (++thread_index < THREADS)
		pthread_join(threads[thread_index], NULL);
	render_minimap(game);
	render_cross_hair(game);
	bettermlx_render(game->window);
}

void	update(t_game *game, long long current_time)
{
	update_loop(game, current_time - game->last_update_time,
		game->window->keyboard);
	game->last_update_time = current_time;
}

int	game_loop(t_game *game)
{
	long long	current_time;

	current_time = bettermlx_get_time();
	if (current_time - game->last_render_time >= 17)
		render(game, current_time);
	if (game->screenshot)
		bettermlx_screenshot(game->window->image, "screenshot.bmp");
	if (game->window->keyboard[KEY_ESCAPE] || game->screenshot)
		exit_game(&game, OK, "Game exited successfully.");
	if (current_time - game->last_update_time >= 17)
		update(game, current_time);
	return (1);
}
