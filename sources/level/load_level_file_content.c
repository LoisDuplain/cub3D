/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_level_file_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:22:03 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/24 12:41:58 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**load_level_file_content(char *level_file_path)
{
	char	**file_content;

	file_content = ft_get_file_content(level_file_path);
	if (file_content == NULL)
		return (NULL);
	return (file_content);
}
