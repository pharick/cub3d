/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:34:22 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/06 16:25:13 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

# include <stdint.h>
# include <fcntl.h>
# include <unistd.h>
# include "structs.h"

typedef struct	s_bmp_header
{
	uint32_t	size;
	uint32_t	reserved;
	uint32_t	offset;
}				t_bmp_header;

typedef struct	s_bmp_info_header
{
	uint32_t	info_size;
	int32_t		width;
	int32_t		height;
	uint16_t	color_planes;
	uint16_t	color_depth;
	uint32_t	compression_method;
	uint32_t	data_size;
	int32_t		h_res;
	int32_t		v_res;
	uint32_t	color_table;
	uint32_t	important_colors;
}				t_bmp_info_header;

int				save_bitmap(t_vars *vars);

#endif
