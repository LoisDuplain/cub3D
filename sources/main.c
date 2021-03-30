/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:24:50 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/24 18:02:08 by lduplain         ###   ########lyon.fr   */
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
	/* printf("1 - %d\n", ft_str_endwith("Je suis une phrase.", ".") == 1);
	printf("2 - %d\n", ft_str_endwith("Je suis une phrase.", "e.") == 1);
	printf("3 - %d\n", ft_str_endwith("Je suis une phrase.", ".e") == 0);
	printf("4 - %d\n", ft_str_endwith("Je suis une phrase.", "se.") == 1);
	printf("5 - %d\n", ft_str_endwith("Je suis une phrase.", "pse.") == 0);
	printf("6 - %d\n", ft_str_endwith("Je suis une phrase.", " se.") == 0);
	printf("7 - %d\n", ft_str_endwith("Je suis une phrase.", NULL) == 0);
	printf("8 - %d\n", ft_str_endwith(NULL, NULL) == 0);
	printf("9 - %d\n", ft_str_endwith(NULL, "rjfhe") == 0);
	printf("9 - %d\n", ft_str_endwith("a", "rjfhe") == 0);
	printf("10 - %d\n", ft_str_endwith("a", "a") == 1);
	printf("11 - %d\n", ft_str_endwith("a", "") == 0);
	printf("12 - %d\n", ft_str_endwith("a", "rtirg") == 0);
	printf("13 - %d\n", ft_str_endwith("abc", "abC") == 0);
	printf("14 - %d\n", ft_str_endwith("abc", "aBc") == 0);
	printf("15 - %d\n", ft_str_endwith("abc", "aBC") == 0);
	printf("16 - %d\n", ft_str_endwith("abc", "abc") == 1);
	printf("17 - %d\n", ft_str_endwith("./path_to_the_north_texture", ".xpm") == 0);
	printf("18 - %d\n", ft_str_endwith("./path_to_the_north_texture.xpm", ".xpm") == 1);
	printf("19 - %d\n", ft_str_endwith("./path_to_the_north_texture. xpm", ".xpm") == 0);
	printf("20 - %d\n", ft_str_endwith("./path_to_the_north_texture.xpm", ". xpm") == 0); */
	return (0);
}
