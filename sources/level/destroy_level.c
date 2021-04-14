/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_level.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:21:48 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 17:01:53 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*destroy_level(t_level **level)
{
	int		texture_index;

	if (*level != NULL)
	{
		ft_destroy_file_content(&(*level)->file_content);
		texture_index = -1;
		while (++texture_index < 7)
			destroy_empty_texture(&(*level)->empty_textures[texture_index]);
		ft_destroy_file_content(&(*level)->map_content);
		free(*level);
		*level = NULL;
	}
	return (NULL);
}
