/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:13:05 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/30 08:53:01 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*destroy_game(t_game **game)
{
	if (*game != NULL)
	{
		destroy_level(&(*game)->current_level);
		free(*game);
		*game = NULL;
	}
	return (NULL);
}
