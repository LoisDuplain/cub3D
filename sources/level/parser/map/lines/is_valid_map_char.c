/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:12:12 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/01 15:17:15 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	is_valid_map_char(char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == '2')
		return (TRUE);
	if (is_player_char(c))
		return (TRUE);
	return (FALSE);
}
