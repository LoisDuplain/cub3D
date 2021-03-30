/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:34:29 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/24 16:06:25 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_level	*load_level(char *level_file_path)
{
	t_level	*level;

	level = create_level();
	if (level == NULL)
		return (NULL);
	level->file_content = load_level_file_content(level_file_path);
	if (level->file_content == NULL)
		return (set_log_tlevel(level, ERROR, \
		"(LEVEL LOADING) Can't get file content."));
	if (!parse_level(level))
		return (level);
	return (set_log_tlevel(level, OK, \
	"(LEVEL LOADING) Level succesfully loaded."));
}
