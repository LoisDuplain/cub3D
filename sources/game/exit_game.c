/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:34:10 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/30 08:53:02 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_game(t_game **game, t_log_type log_type, char *message)
{
	display_log_type(log_type);
	ft_putchar('\n');
	ft_putstr_nl(message);
	destroy_game(game);
	exit(0);
}
