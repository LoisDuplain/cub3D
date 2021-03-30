/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_clean_display.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:40:04 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/25 11:45:39 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bettermlx_clean_display(t_window *window)
{
	t_color	clean_color;
	int		x;
	int		y;

	clean_color = create_color((char)0, (char)0, (char)0, (char)0);
	x = 0;
	while (x < window->image->width)
	{
		y = 0;
		while (y < window->image->height)
		{
			bettermlx_pixel_put(window, create_vector(x, y, 0), clean_color, 1);
			y++;
		}
		x++;
	}
}
