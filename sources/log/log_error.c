/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:07:01 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/06 16:26:28 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	log_error(t_log_type log_type, char *message)
{
	display_log_type(log_type);
	ft_putstr(": ");
	ft_putstr_nl(message);
}
