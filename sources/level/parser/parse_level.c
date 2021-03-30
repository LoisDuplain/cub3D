/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:13:19 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/30 09:21:01 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	parse_level(t_level *level)
{
	t_bool			valid_parsing;
	size_t			line_index;
	char			**splitted;
	size_t			splitted_size;
	t_param_type	param_type;

	valid_parsing = TRUE;
	line_index = 0;
	while (level->file_content[line_index] && valid_parsing)
	{
		if (!level->have_required_params)
		{
			splitted = ft_split(level->file_content[line_index], " ");
			splitted_size = ft_get_splitted_size(splitted);
			if (splitted_size > 0)
			{
				param_type = get_param_type(splitted[0]);
				valid_parsing = parse_param(level, param_type, splitted, splitted_size);
			}
			ft_destroy_splitted(&splitted);
		}
		line_index++;
	}
	return (valid_parsing);
}
