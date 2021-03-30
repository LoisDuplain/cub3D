/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_xpm_empty_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:23:50 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/30 10:48:09 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	parse_xpm_empty_texture(t_level *level, \
	t_empty_texture **empty_texture, \
	char *path)
{
	t_file			*file;

	file = ft_open_file(path, O_RDONLY);
	if (file == NULL)
	{
		set_log_tlevel(level, ERROR, \
		"Can't open texture file.");
		return (FALSE);
	}
	ft_close_file(file);
	*empty_texture = create_empty_texture();
	if (*empty_texture == NULL)
	{
		set_log_tlevel(level, ERROR, \
		"(t_empty_texture *)empty_texture allocation failed.");
		return (FALSE);
	}
	(*empty_texture)->texture_file_path = ft_strdup(path, FALSE);
	return (TRUE);
}
