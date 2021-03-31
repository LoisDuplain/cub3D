/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_level_parser_func.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:14:07 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/31 10:38:55 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_LEVEL_PARSER_FUNC_H
# define CUB3D_LEVEL_PARSER_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "./cub3d.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Parse level parameters.
**	./level/parser/parse_level_params.c
*/
t_bool			parse_level_params(t_level *level);

/*
**	Get param type from string (char *)param_type_str.
**	./level/parser/parse_level.c
*/
t_param_type	get_param_type(char *param_type_str);

/*
**	Parse param contained in level file.
**	./level/parser/parse_param.c
*/
t_bool			parse_param(t_level *level, \
	t_param_type param_type, \
	char **splitted, \
	size_t splitted_size);

/*
**	Parse param resolution contained in level file.
**	./level/parser/parse_resolution_param.c
*/
t_bool			parse_resolution_param(t_level *level, \
	char **splitted, \
	size_t splitted_size);

/*
**	Parse north param contained in level file.
**	./level/parser/parse_resolution_param.c
*/
t_bool			parse_north_param(t_level *level, \
	char **splitted, \
	size_t splitted_size);

/*
**	Parse south param contained in level file.
**	./level/parser/parse_south_param.c
*/
t_bool			parse_south_param(t_level *level, \
	char **splitted, \
	size_t splitted_size);

/*
**	Parse west param contained in level file.
**	./level/parser/parse_west_param.c
*/
t_bool			parse_west_param(t_level *level, \
	char **splitted, \
	size_t splitted_size);

/*
**	Parse east param contained in level file.
**	./level/parser/parse_east_param.c
*/
t_bool			parse_east_param(t_level *level, \
	char **splitted, \
	size_t splitted_size);

/*
**	Parse sprite param contained in level file.
**	./level/parser/parse_sprite_param.c
*/
t_bool			parse_sprite_param(t_level *level, \
	char **splitted, \
	size_t splitted_size);

/*
**	Parse floor param contained in level file.
**	./level/parser/parse_floor_param.c
*/
t_bool			parse_floor_param(t_level *level, \
	char **splitted, \
	size_t splitted_size);

/*
**	Parse ceiling param contained in level file.
**	./level/parser/parse_ceiling_param.c
*/
t_bool			parse_ceiling_param(t_level *level, \
	char **splitted, \
	size_t splitted_size);

/*
**	Parse a new empty_texture (color or texture file path).
**	./level/parser/parse_empty_texture.c
*/
t_bool			parse_empty_texture(t_level *level, \
	t_empty_texture **empty_texture, \
	char *argument);

/*
**	Parse a new empty_texture with xpm texture path.
**	./level/parser/parse_xpm_empty_texture.c
*/
t_bool			parse_xpm_empty_texture(t_level *level, \
	t_empty_texture **empty_texture, \
	char *path);

/*
**	Parse a new empty_texture with string color.
**	./level/parser/parse_color_empty_texture.c
*/
t_bool			parse_color_empty_texture(t_level *level, \
	t_empty_texture **empty_texture, \
	char *color);

/*
**	Parse splitted color into empty texture.
**	./level/parser/parse_splitted_color_in_empty_texture.c
*/
t_bool			parse_splitted_color_in_empty_texture(t_level *level, \
	t_empty_texture **empty_texture, \
	char **splitted_color);

/*
**	Check if level have parsed all required parameters.
**	./level/parser/check_required_params.c
*/
t_bool			check_required_params(t_level *level);

#endif