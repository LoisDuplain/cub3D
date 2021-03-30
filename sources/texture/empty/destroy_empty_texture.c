/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_empty_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:56:49 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/30 08:51:50 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*destroy_empty_texture(t_empty_texture **empty_texture)
{
	if (*empty_texture != NULL)
	{
		free((*empty_texture)->texture_file_path);
		(*empty_texture)->texture_file_path = NULL;
		free(*empty_texture);
		*empty_texture = NULL;
	}
	return (NULL);
}
