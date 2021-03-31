/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:24:50 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/31 10:22:32 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (argc <= 1)
		exit_game(NULL, ERROR, "You must specify a map path.");
	else if (argc == 2)
		start_game(argv[1], FALSE);
	else if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") == 0)
			start_game(argv[1], TRUE);
		else
			exit_game(NULL, ERROR, \
			"Second argument is not valid. Did you mean \"--save\" ?");
	}
	else
		exit_game(NULL, ERROR, "Too many arguments.");
	return (0);
}
