/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_init_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:33:52 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/28 13:05:02 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_window	*bettermlx_init_window(
	char *title,
	int width,
	int height,
	int divider)
{
	t_window	*window;

	window = ft_calloc(1, sizeof(t_window));
	if (window == NULL)
		return (NULL);
	window->title = title;
	window->width = width;
	window->height = height;
	window->real_width = width / divider;
	window->real_height = height / divider;
	window->divider = divider;
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, width, height, title);
	window->image = bettermlx_init_image(window, window->width, window->height);
	bettermlx_hook(window, KEY_PRESS, key_press_hook, window);
	bettermlx_hook(window, KEY_RELEASE, key_release_hook, window);
	mlx_do_key_autorepeatoff(window->mlx_ptr);
	return (window);
}
