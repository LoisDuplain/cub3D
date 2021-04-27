/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:36:14 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/27 17:14:06 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_minimap(t_game *game)
{
	int		y;
	int		x;
	int		mx;
	int		my;
	t_color	color;

	y = -1;
	while (++y < game->window->real_height / 4)
	{
		x = -1;
		while (++x < game->window->real_width / 4)
		{
			my = y * game->cur_lvl->map_height * 4 / game->window->real_height;
			mx = x * game->cur_lvl->map_width * 4 / game->window->real_width;
			if (game->cur_lvl->map_content[my][mx] == 0)
				color = create_color(0, 0, 0, 0);
			else if (game->cur_lvl->map_content[my][mx] == 1)
				color = create_color(0, 255, 255, 255);
			else if (game->cur_lvl->map_content[my][mx] == 2)
				color = create_color(0, 0, 255, 0);
			else
				color = create_color(255, 255, 0, 0);
			bettermlx_pixel_put(
				game->window,
				create_vector(
					x,
					y,
					0
					),
				color,
				1
				);
		}
	}
}

int	game_loop(t_game *game)
{
	t_render_thread	render_threads[THREADS];
	pthread_t		threads[THREADS];
	int				size;
	int				i;
	long long		start_time;

	start_time = bettermlx_get_time();
	size = game->rays_size / THREADS;
	i = -1;
	while (++i < THREADS)
	{
		render_threads[i] = create_render_thread(game,
				size * i, size * (i + 1));
		pthread_create(&threads[i], NULL, &render_loop, &render_threads[i]);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(threads[i], NULL);
	render_minimap(game);
	render_cross_hair(game);
	bettermlx_render(game->window);
	if (game->window->keyboard[KEY_ESCAPE])
		exit_game(&game, OK, "Game exited successfully.");
	update_loop(game, bettermlx_get_time() - start_time,
		game->window->keyboard);
	return (1);
}
