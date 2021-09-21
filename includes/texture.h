/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 10:54:11 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/04 23:27:31 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "mlx.h"
# include "structs.h"

t_texture	load_xpm_texture(void *mlx, char *path);
int			get_pixel(t_texture texture, int x, int y);
t_texture	get_texture(t_textures textures, int side);
void		pixel_put(t_frame *frame, int x, int y, int color);

#endif
