/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_destroy_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:52:36 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/30 08:57:32 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*bettermlx_destroy_window(t_window **window)
{
	if (*window == NULL)
	{
		bettermlx_destroy_image(*window, &(*window)->image);
		mlx_destroy_window((*window)->mlx_ptr, (*window)->win_ptr);
		mlx_destroy_mlx((*window)->mlx_ptr);
		free(*window);
	}
	return (NULL);
}
