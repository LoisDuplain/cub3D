/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_level.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:21:48 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/30 11:13:24 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*destroy_level(t_level **level)
{
	if (*level != NULL)
	{
		ft_destroy_file_content(&(*level)->file_content);
		destroy_empty_texture(&(*level)->north_empty_texture);
		destroy_empty_texture(&(*level)->south_empty_texture);
		destroy_empty_texture(&(*level)->west_empty_texture);
		destroy_empty_texture(&(*level)->east_empty_texture);
		free(*level);
		*level = NULL;
	}
	return (NULL);
}
