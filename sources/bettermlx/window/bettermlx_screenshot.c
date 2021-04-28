/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_screenshot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:55:05 by lduplain          #+#    #+#             */
/*   Updated: 2021/04/28 14:06:31 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bdata(t_image *image, int fd)
{
	unsigned char	buffer[4];
	t_color			color;
	int				x;
	int				y;

	y = image->height;
	while (y > 0)
	{
		x = 0;
		while (x < image->width)
		{
			color = bettermlx_get_color(image, x, y);
			buffer[0] = (unsigned char)(color.b);
			buffer[1] = (unsigned char)(color.g);
			buffer[2] = (unsigned char)(color.r);
			buffer[3] = (unsigned char)(color.a);
			write(fd, buffer, 4);
			x++;
		}
		y--;
	}
}

void	ft_binfo(t_image *image, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = image->width;
	header[4] = (unsigned char)(n % 256);
	header[5] = (unsigned char)(n / 256 % 256);
	header[6] = (unsigned char)(n / 256 / 256 % 256);
	header[7] = (unsigned char)(n / 256 / 256 / 256);
	n = image->height;
	header[8] = (unsigned char)(n % 256);
	header[9] = (unsigned char)(n / 256 % 256);
	header[10] = (unsigned char)(n / 256 / 256 % 256);
	header[11] = (unsigned char)(n / 256 / 256 / 256);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void	ft_bfile(t_image *image, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = image->width * image->height * 4 + 54;
	header[2] = (unsigned char)(n % 256);
	header[3] = (unsigned char)(n / 256 % 256);
	header[4] = (unsigned char)(n / 256 / 256 % 256);
	header[5] = (unsigned char)(n / 256 / 256 / 256);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

void	bettermlx_screenshot(t_image *image, char *file_name)
{
	int	fd;

	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	ft_bfile(image, fd);
	ft_binfo(image, fd);
	ft_bdata(image, fd);
	close(fd);
}
