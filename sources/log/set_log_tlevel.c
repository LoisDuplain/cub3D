/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_log_tlevel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:55:01 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/24 12:55:49 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_level	*set_log_tlevel(t_level *level, t_log_type log_type, char *log_message)
{
	level->log_type = log_type;
	level->log_message = log_message;
	return (level);
}
