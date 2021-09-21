/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:34:13 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/06 16:31:48 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

static void	write_header(int fd, t_vars *vars)
{
	t_bmp_header	header;

	header.size = 54 + vars->config.res.w * vars->config.res.h * 4;
	header.reserved = 0;
	header.offset = 54;
	write(fd, "BM", 2);
	write(fd, &header, 12);
}

static void	write_info(int fd, t_vars *vars)
{
	t_bmp_info_header	info;

	info.info_size = 40;
	info.width = vars->config.res.w;
	info.height = -vars->config.res.h;
	info.color_planes = 1;
	info.color_depth = 32;
	info.compression_method = 0;
	info.data_size = 0;
	info.h_res = 0;
	info.v_res = 0;
	info.color_table = 0;
	info.important_colors = 0;
	write(fd, &info, 40);
}

void		write_pixel(int fd, t_frame texture, int x, int y)
{
	char			*src;
	int				offset;
	unsigned int	color;

	offset = (y * texture.size_line + x * (texture.bits_per_pixel / 8));
	src = texture.addr + offset;
	color = *(unsigned int*)src;
	write(fd, &color, 4);
}

void		write_data(int fd, t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->config.res.h)
	{
		x = 0;
		while (x < vars->config.res.w)
		{
			write_pixel(fd, vars->buffer, x, y);
			x++;
		}
		y++;
	}
}

int			save_bitmap(t_vars *vars)
{
	int	fd;

	fd = open("frame.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	write_header(fd, vars);
	write_info(fd, vars);
	write_data(fd, vars);
	close(fd);
	return (0);
}
