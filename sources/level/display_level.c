/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_level.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 09:54:21 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/14 17:02:25 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_level(t_level *level)
{
	dprintf(1, "Level:\n");
	
	dprintf(1, "   File content:\n");
	size_t i = -1;
	while (level->file_content[++i])
		dprintf(1, "      \"%s\"\n", level->file_content[i]);

	dprintf(1, "   Params line index: {%zu}\n", level->params_line_index);

	dprintf(1, "   Window:\n");
	dprintf(1, "      Width: {%d}\n", level->window_width);
	dprintf(1, "      Height: {%d}\n", level->window_height);

	/* dprintf(1, "   North empty texture:\n");
	if (level->north_empty_texture != NULL)
	{
		dprintf(1, "      Texture path: {%s}\n", level->north_empty_texture->texture_file_path);
		dprintf(1, "      Color: {r: %d, g: %d, b: %d}\n", level->north_empty_texture->color.r, level->north_empty_texture->color.g, level->north_empty_texture->color.b);
	}
	else
		dprintf(1, "      NULL\n");

	dprintf(1, "   South empty texture:\n");
	if (level->south_empty_texture != NULL)
	{
		dprintf(1, "      Texture path: {%s}\n", level->south_empty_texture->texture_file_path);
		dprintf(1, "      Color: {r: %d, g: %d, b: %d}\n", level->south_empty_texture->color.r, level->south_empty_texture->color.g, level->south_empty_texture->color.b);
	}
	else
		dprintf(1, "      NULL\n");
		
	dprintf(1, "   West empty texture:\n");
	if (level->west_empty_texture != NULL)
	{
		dprintf(1, "      Texture path: {%s}\n", level->west_empty_texture->texture_file_path);
		dprintf(1, "      Color: {r: %d, g: %d, b: %d}\n", level->west_empty_texture->color.r, level->west_empty_texture->color.g, level->west_empty_texture->color.b);
	}
	else
		dprintf(1, "      NULL\n");
	
	dprintf(1, "   East empty texture:\n");
	if (level->east_empty_texture != NULL)
	{
		dprintf(1, "      Texture path: {%s}\n", level->east_empty_texture->texture_file_path);
		dprintf(1, "      Color: {r: %d, g: %d, b: %d}\n", level->east_empty_texture->color.r, level->east_empty_texture->color.g, level->east_empty_texture->color.b);
	}
	else
		dprintf(1, "      NULL\n");
		
	dprintf(1, "   Sprite empty texture:\n");
	if (level->sprite_empty_texture != NULL)
	{
		dprintf(1, "      Texture path: {%s}\n", level->sprite_empty_texture->texture_file_path);
		dprintf(1, "      Color: {r: %d, g: %d, b: %d}\n", level->sprite_empty_texture->color.r, level->sprite_empty_texture->color.g, level->sprite_empty_texture->color.b);
	}
	else
		dprintf(1, "      NULL\n");
		
	dprintf(1, "   Floor empty texture:\n");
	if (level->floor_empty_texture != NULL)
	{
		dprintf(1, "      Texture path: {%s}\n", level->floor_empty_texture->texture_file_path);
		dprintf(1, "      Color: {r: %d, g: %d, b: %d}\n", level->floor_empty_texture->color.r, level->floor_empty_texture->color.g, level->floor_empty_texture->color.b);
	}
	else
		dprintf(1, "      NULL\n");
		
	dprintf(1, "   Ceiling empty texture:\n");
	if (level->ceiling_empty_texture != NULL)
	{
		dprintf(1, "      Is skybox: {%s}\n", (level->ceiling_is_skybox) ? "TRUE" : "FALSE");
		dprintf(1, "      Texture path: {%s}\n", level->ceiling_empty_texture->texture_file_path);
		dprintf(1, "      Color: {r: %d, g: %d, b: %d}\n", level->ceiling_empty_texture->color.r, level->ceiling_empty_texture->color.g, level->ceiling_empty_texture->color.b);
	}
	else
		dprintf(1, "      NULL\n"); */
	
	dprintf(1, "   Map width: {%zu}\n", level->map_width);
	dprintf(1, "   Map height: {%zu}\n", level->map_height);
	
	dprintf(1, "   Map content:\n");
	i = -1;
	while (level->map_content[++i])
	{
		size_t j = -1;
		while (++j < level->map_width)
		{
			if (level->map_content[i][j] == -2)
				ft_putchar('-');
			else if (level->map_content[i][j] == -1)
				ft_putchar('_');
			else if (level->map_content[i][j] == 0)
				ft_putchar(' ');
			else if (level->map_content[i][j] == 1)
				ft_putchar('*');
			else
				ft_putchar(level->map_content[i][j] + 48);
		}
		ft_putchar('\n');
	}

	dprintf(1, "   Player:\n");
	dprintf(1, "      Location: {vx: %f, vy: %f, vz: %f}\n", level->player.location.vx, level->player.location.vy, level->player.location.vz);
	dprintf(1, "      Yaw: %f\n", level->player.yaw);
	dprintf(1, "      Pitch: %f\n", level->player.pitch);

	dprintf(1, "   Log:\n");
	dprintf(1, "      Type: {");
	display_log_type(level->log_type);
	dprintf(1, "}\n");
	dprintf(1, "      Message: {%s}\n", level->log_message);
}
