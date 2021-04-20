/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_level_parser_func.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:14:07 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/20 12:35:31 by lduplain         ###   ########lyon.fr   */
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
**	./level/parser/parse_level_params.c-
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

/*
**	Parse level map.
**	./level/parser/parse_level_map.c
*/
t_bool			parse_level_map(t_level *level);

/*
**	Get map width in level->file_content.
**	./level/parser/get_map_width.c
*/
size_t			get_map_width(t_level *level);

/*
**	Get map height in level->file_content.
**	./level/parser/get_map_width.c
*/
size_t			get_map_height(t_level *level);

/*
**	Check if char c is a valid char to be contained in map.
**	./level/parser/is_valid_map_char.c
*/
t_bool			is_valid_map_char(char c);

/*
**	Check if char c is a valid player char.
**	./level/parser/is_player_char.c
*/
t_bool			is_player_char(char c);

/*
**	Check if lines in map level->file_content are valid.
**	./level/parser/is_valid_map_char.c
*/
t_bool			are_valid_map_lines(t_level *level);

/*
**	Create map content.
**	./level/parser/create_map_content.c
*/
t_bool			create_map_content(t_level *level);

/*
**	Duplicates map lines into level->map_content.
**	./level/parser/fill_map_content.c
*/
t_bool			fill_map_content(t_level *level);

/*
**	Find player in level->map_content.
**	./level/parser/find_player.c
*/
void			find_player(t_level *level);

/*
**	Check if map contains one player.
**	./level/parser/single_player_map.c
*/
t_bool			single_player_map(t_level *level);

/*
**	Get the player spawn yaw.
**	./level/parser/get_player_spawn_facing.c
*/
float			get_player_spawn_facing(char c);

/*
**	Convert map with basic chars.
**	./level/parser/convert_map.c
*/
void			convert_map(t_level *level);

/*
**	Validate map.
**	./level/parser/validate_map.c
*/
t_bool			validate_map(t_level *level, int x, int y);

/*
**	Count sprites in map.
**	./level/parser/count_sprites.c
*/
int				count_sprites(t_level *level);

/*
**	Parse sprites in map.
**	./level/parser/parse_sprites.c
*/
t_bool			parse_sprites(t_level *level);

/*
**	Create sprite.
**	./level/parser/parse_sprites.c
*/
t_sprite	create_sprite(t_plane plane, t_vector3 position);

#endif