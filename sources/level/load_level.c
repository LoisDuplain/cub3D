/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:34:29 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/01 11:52:39 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_level	*load_level(char *level_file_path)
{
	t_level	*level;

	level = create_level();
	if (level == NULL)
		return (NULL);
	if (!ft_str_endwith(level_file_path, ".cub"))
		return (set_log_tlevel(level, ERROR, "Wrong level file extension."));
	level->file_content = ft_get_file_content(level_file_path);
	if (level->file_content == NULL)
		return (set_log_tlevel(level, ERROR, "Can't get level file content."));
	if (!parse_level_params(level))
		return (level);
	if (!parse_level_map(level))
		return (level);
	return (set_log_tlevel(level, OK, "Level succesfully loaded."));
}
