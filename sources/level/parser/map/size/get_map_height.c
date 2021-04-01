/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_height.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:50:21 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/01 14:16:31 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	get_map_height(t_level *level)
{
	size_t	eof_line_index;

	eof_line_index = ft_get_splitted_size(level->file_content) - 1;
	return (eof_line_index - level->params_line_index + 1);
}
