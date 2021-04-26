/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:07:01 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/26 18:03:23 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	log_message(t_log_type log_type, char *message)
{
	display_log_type(log_type);
	ft_putstr(": ");
	ft_putstr_nl(message);
}
