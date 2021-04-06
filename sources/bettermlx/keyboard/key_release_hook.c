/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:37:14 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/06 16:03:30 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_release_hook(int key_code, t_window *window)
{
	window->keyboard[key_code] = FALSE;
	ft_printf("%d released.\n", key_code);
	return (0);
}
