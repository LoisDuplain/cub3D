/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:23:56 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/23 14:36:59 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_param_type	get_param_type(char *param_type_str)
{
	if (ft_strcmp(param_type_str, "R") == 0)
		return (RESOLUTION_PARAM);
	else if (ft_strcmp(param_type_str, "NO") == 0)
		return (NORTH_PARAM);
	else if (ft_strcmp(param_type_str, "SO") == 0)
		return (SOUTH_PARAM);
	else if (ft_strcmp(param_type_str, "WE") == 0)
		return (WEST_PARAM);
	else if (ft_strcmp(param_type_str, "EA") == 0)
		return (EAST_PARAM);
	else if (ft_strcmp(param_type_str, "S") == 0)
		return (SPRITE_PARAM);
	else if (ft_strcmp(param_type_str, "F") == 0)
		return (FLOOR_PARAM);
	else if (ft_strcmp(param_type_str, "C") == 0)
		return (CEILING_PARAM);
	return (UNKNOWN);
}
