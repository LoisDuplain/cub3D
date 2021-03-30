/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_log_func.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:51:16 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/24 13:13:18 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_LOG_FUNC_H
# define CUB3D_LOG_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "./cub3d.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Display log type (t_log_type)log_type whithout line break at the end.
**	./log/display_log_type.c
*/
void	display_log_type(t_log_type log_type);

/*
**	Set log in (t_level *)level.
**	./log/set_log_tlevel.c
*/
t_level	*set_log_tlevel(t_level *level, t_log_type log_type, char *log_message);

/*
**	Log (t_level *)level.
**	./log/log_tlevel.c
*/
void	log_tlevel(t_level *level);

#endif
