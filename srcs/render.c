/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 00:12:16 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/04 23:36:22 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void		line_put(t_frame *frame, int x, t_line line_info,
							t_config config)
{
	int		y;
	int		texture_y;
	double	texture_pos;
	int		color;

	texture_pos = line_info.texture_start;
	y = 0;
	while (y < line_info.start)
	{
		pixel_put(frame, x, y, config.textures.ceil);
		y++;
	}
	while (y <= line_info.end)
	{
		texture_y = (int)texture_pos & (line_info.texture.height - 1);
		texture_pos += line_info.texture_step;
		color = get_pixel(line_info.texture, line_info.texture_x, texture_y);
		pixel_put(frame, x, y, color);
		y++;
	}
	while (y < config.res.h)
	{
		pixel_put(frame, x, y, config.textures.floor);
		y++;
	}
}

static t_line	calculate_line(t_dda result, t_config config,
								t_vector ray_dir, t_texture texture)
{
	t_line	line_info;
	int		line_height;
	double	wall_x;

	line_height = (int)(config.res.h / result.wall_dist);
	line_info.start = -line_height / 2 + config.res.h / 2;
	if (line_info.start < 0)
		line_info.start = 0;
	line_info.end = line_height / 2 + config.res.h / 2;
	if (line_info.end >= config.res.h)
		line_info.end = config.res.h - 1;
	if (result.side == EAST_WALL || result.side == WEST_WALL)
		wall_x = config.pos.y + result.wall_dist * ray_dir.y;
	else
		wall_x = config.pos.x + result.wall_dist * ray_dir.x;
	wall_x -= floor(wall_x);
	line_info.texture_x = (int)(wall_x * (double)texture.width);
	if ((result.side >= 2 && result.side <= 3 && ray_dir.x > 0) ||
		(result.side >= 0 && result.side <= 1 && ray_dir.y < 0))
		line_info.texture_x = texture.width - line_info.texture_x - 1;
	line_info.texture_step = 1.0 * texture.height / line_height;
	line_info.texture_start = (line_info.start - config.res.h / 2
								+ line_height / 2) * line_info.texture_step;
	line_info.texture = texture;
	return (line_info);
}

static void		raycast(t_frame *frame, t_vars *vars)
{
	t_vector	ray_dir;
	double		camera_x;
	t_dda		result;
	int			x;
	t_line		line_info;

	x = 0;
	while (x < vars->config.res.w)
	{
		camera_x = 2 * (double)(vars->config.res.w - x) /
							vars->config.res.w - 1;
		ray_dir.x = vars->config.dir.x + vars->config.plane.x * camera_x;
		ray_dir.y = vars->config.dir.y + vars->config.plane.y * camera_x;
		result = dda(vars->config, ray_dir);
		vars->z_buffer[x] = result.wall_dist;
		line_info = calculate_line(result, vars->config, ray_dir,
							get_texture(vars->config.textures, result.side));
		line_put(frame, x, line_info, vars->config);
		x++;
	}
}

void			render(t_vars *vars)
{
	raycast(&vars->buffer, vars);
	render_sprites(&vars->buffer, vars);
}

int				next_frame(t_vars *vars)
{
	t_frame	tmp;

	move_player(vars->keys, &vars->config);
	render(vars);
	mlx_clear_window(vars->mlx, vars->window);
	mlx_put_image_to_window(vars->mlx, vars->window, vars->buffer.img, 0, 0);
	tmp = vars->frame;
	vars->frame = vars->buffer;
	vars->buffer = tmp;
	return (0);
}
