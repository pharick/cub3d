/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:11:59 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/05 15:13:02 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

enum			e_walls
{
	NORTH_WALL,
	SOUTH_WALL,
	EAST_WALL,
	WEST_WALL
};

typedef struct	s_frame {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_frame;

typedef struct	s_texture {
	void	*img;
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_texture;

typedef struct	s_res
{
	int	w;
	int	h;
}				t_res;

typedef struct	s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct	s_textures
{
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	t_texture	sprite;
	int			floor;
	int			ceil;
}				t_textures;

typedef struct	s_sprite
{
	t_vector	coords;
	double		dist;
}				t_sprite;

typedef struct	s_config
{
	t_res		res;
	t_textures	textures;
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	char		**map;
	int			map_height;
	t_sprite	*sprites;
	int			*sprites_order;
	int			sprites_count;

}				t_config;

typedef struct	s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	right;
	int	left;
}				t_keys;

typedef struct	s_vars
{
	void		*mlx;
	void		*window;
	t_frame		frame;
	t_frame		buffer;
	t_config	config;
	t_keys		keys;
	double		*z_buffer;
}				t_vars;

typedef struct	s_dda
{
	double	wall_dist;
	int		side;
}				t_dda;

typedef struct	s_line
{
	int			start;
	int			end;
	t_texture	texture;
	int			texture_x;
	double		texture_start;
	double		texture_step;
}				t_line;

typedef struct	s_sprite_params
{
	t_vector	transform;
	int			sprite_screen_x;
	int			width;
	int			height;
	int			start_x;
	int			end_x;
	int			start_y;
	int			end_y;
}				t_sprite_params;

#endif
