/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_tlevel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:03:48 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/24 13:14:00 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	log_tlevel(t_level *level)
{
	display_log_type(level->log_type);
	ft_putstr(": ");
	ft_putstr_nl(level->log_message);
}
