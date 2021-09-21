/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 10:54:02 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/04 23:24:59 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

t_texture	load_xpm_texture(void *mlx, char *path)
{
	t_texture	texture;

	texture.img = mlx_xpm_file_to_image(mlx, path, &texture.width,
										&texture.height);
	if (!texture.img)
		return (texture);
	texture.addr = mlx_get_data_addr(texture.img, &texture.bits_per_pixel,
									&texture.size_line, &texture.endian);
	return (texture);
}

int			get_pixel(t_texture texture, int x, int y)
{
	char	*src;
	int		offset;

	offset = (y * texture.size_line + x * (texture.bits_per_pixel / 8));
	src = texture.addr + offset;
	return (*(unsigned int*)src);
}

t_texture	get_texture(t_textures textures, int side)
{
	if (side == NORTH_WALL)
		return (textures.north);
	if (side == SOUTH_WALL)
		return (textures.south);
	if (side == EAST_WALL)
		return (textures.east);
	return (textures.west);
}

void		pixel_put(t_frame *frame, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * frame->size_line + x * (frame->bits_per_pixel / 8));
	dst = frame->addr + offset;
	*(unsigned int*)dst = color;
}
