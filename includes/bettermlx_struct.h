/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:32:26 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/28 13:23:09 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BETTERMLX_STRUCT_H
# define BETTERMLX_STRUCT_H

/*
**	START CUSTOM INCLUDES
*/

# include "cub3d.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	START STRUCTURES
*/

typedef struct s_image
{
	int			width;
	int			height;
	void		*img_ptr;
	char		*img_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}	t_image;

typedef struct s_window
{
	char	*title;
	int		width;
	int		height;
	int		real_width;
	int		real_height;
	int		divider;
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	*image;
	t_bool	keyboard[384];
}	t_window;

/*
**	END STRUCTURES
*/

/*
**	START ENUMS
*/

typedef enum e_x11event
{
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	BUTTON_PRESS = 4,
	BUTTON_RELESE = 5,
	MOTION_NOTIFY = 6,
	ENTER_NOTIFY = 7,
	LEAVE_NOTIFY = 8,
	FOCUS_IN = 9,
	FOCUS_OUT = 10,
	KEYMAP_NOTIFY = 11,
	EXPOSE = 12,
	GRAPHICS_EXPOSE = 13,
	NO_EXPOSE = 14,
	VISIBILITY_NOTIFY = 15,
	CREATE_NOTIFY = 16,
	DESTROY_NOTIFY = 17,
	UNMAP_NOTIFY = 18,
	MAP_NOTIFY = 19,
	MAP_REQUEST = 20,
	REPARENT_NOTIFY = 21,
	CONFIGURE_NOTIFY = 22,
	CONFIGURE_REQUEST = 23,
	GRAVITY_NOTIFY = 24,
	RESIZE_REQUEST = 25,
	CIRCULATE_NOTIFY = 26,
	CIRCULATE_REQUEST = 27,
	PROPERTY_NOTIFY = 28,
	SELECTION_CLEAR = 29,
	SELECTION_REQUEST = 30,
	SELECTION_NOTIFY = 31,
	COLORMAP_NOTIFY = 32,
	CLIENT_MESSAGE = 33,
	MAPPING_NOTIFY = 34,
	GENERIC_EVENT = 35,
	LAST_EVENT = 36,
}				t_x11event;

typedef enum e_key
{
	KEY_A = 0,
	KEY_B = 11,
	KEY_C = 8,
	KEY_D = 2,
	KEY_E = 14,
	KEY_F = 3,
	KEY_G = 5,
	KEY_H = 4,
	KEY_I = 34,
	KEY_J = 38,
	KEY_K = 40,
	KEY_L = 37,
	KEY_M = 46,
	KEY_N = 45,
	KEY_O = 31,
	KEY_P = 35,
	KEY_Q = 12,
	KEY_R = 15,
	KEY_S = 1,
	KEY_T = 17,
	KEY_U = 32,
	KEY_V = 9,
	KEY_W = 13,
	KEY_X = 7,
	KEY_Y = 16,
	KEY_Z = 6,
	KEY_ZERO = 29,
	KEY_ONE = 18,
	KEY_TWO = 19,
	KEY_THREE = 20,
	KEY_FOUR = 21,
	KEY_FIVE = 23,
	KEY_SIX = 22,
	KEY_SEVEN = 26,
	KEY_EIGHT = 28,
	KEY_NINE = 25,
	KEY_BRACE_R = 30,
	KEY_BRACE_L = 33,
	KEY_TAB = 48,
	KEY_PLUS = 69,
	KEY_MINUS = 78,
	KEY_SEMI = 41,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126,
	KEY_ESCAPE = 53,
	KEY_LESS = 43,
	KEY_GREATER = 47,
	KEY_SPACE = 49,
	KEY_PAGE_UP = 116,
	KEY_PAGE_DOWN = 121,
}				t_key;

typedef enum e_ecolor
{
	BLACK = 0x00000000,
	WHITE = 0x00FFFFFF,
	RED = 0x00FF0000,
	GREEN = 0x0000FF00,
	BLUE = 0x000000FF,
	YELLOW = 0x00FFFF00,
	PURPLE = 0x00FF00FF,
	CYAN = 0x0000FFFF,
}				t_ecolor;

/*
**	END ENUMS
*/

#endif
