/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:05:50 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/06 13:44:07 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
**	START STANDARD INCLUDES
*/

# include <stdio.h>
# include <math.h>
# include <sys/time.h>

/*
**	END STANDARD INCLUDES
*/

/*
**	START CUSTOM INCLUDES
*/

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# include "./bettermlx_struct.h"
# include "./cub3d_player_struct.h"
# include "./cub3d_texture_struct.h"
# include "./cub3d_empty_texture_struct.h"
# include "./cub3d_log_struct.h"
# include "./cub3d_level_struct.h"
# include "./cub3d_level_parser_struct.h"
# include "./cub3d_game_struct.h"

# include "./bettermlx_func.h"
# include "./cub3d_loop_func.h"
# include "./cub3d_texture_func.h"
# include "./cub3d_empty_texture_func.h"
# include "./cub3d_log_func.h"
# include "./cub3d_level_func.h"
# include "./cub3d_level_parser_func.h"
# include "./cub3d_game_func.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	START DEFINES
*/

# define RADIAN				0.01745

# define MOVEMENT_SPEED		0.003
# define ROTATION_SPEED		0.0015

/*
**	END DEFINES
*/

/*
**	The main function.
**	./main.c
*/
int		main(int argc, char **argv);

#endif
