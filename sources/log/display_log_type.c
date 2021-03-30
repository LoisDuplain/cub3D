/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_log_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:50:05 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/24 12:50:47 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_log_type(t_log_type log_type)
{
	if (log_type == OK)
		ft_putstr("OK");
	else if (log_type == ERROR)
		ft_putstr("Error");
	else if (log_type == NONE)
		ft_putstr("Log message");
	else
		ft_putstr("Unknown log type");
}
