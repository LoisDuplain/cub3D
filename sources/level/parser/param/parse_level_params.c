/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_level_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:13:19 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/01 14:47:22 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	parse_level_params(t_level *level)
{
	t_bool			valid_parsing;
	char			**splitted;
	size_t			splt_size;
	t_param_type	param_type;

	valid_parsing = TRUE;
	while (level->file_content[level->params_line_index] && valid_parsing)
	{
		splitted = ft_split(level->file_content[level->params_line_index], " ");
		splt_size = ft_get_splitted_size(splitted);
		if (splt_size > 0)
		{
			param_type = get_param_type(splitted[0]);
			valid_parsing = parse_param(level, param_type, splitted, splt_size);
		}
		ft_destroy_splitted(&splitted);
		if (!valid_parsing)
			break ;
		level->params_line_index++;
	}
	return (check_required_params(level));
}
