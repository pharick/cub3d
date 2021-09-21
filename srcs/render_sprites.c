/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 18:21:26 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/04 11:20:19 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_sprites.h"

static void				calc_dists(t_config config)
{
	int	i;

	i = 0;
	while (i < config.sprites_count)
	{
		config.sprites[i].dist =
			pow(config.pos.x - config.sprites[i].coords.x, 2) +
			pow(config.pos.y - config.sprites[i].coords.y, 2);
		config.sprites_order[i] = i;
		i++;
	}
}

static void				transform_coords(t_sprite_params *params,
											t_config config, int i)
{
	t_vector	sprite;
	double		inv_det;

	sprite.x = config.sprites[config.sprites_order[i]].coords.x - config.pos.x;
	sprite.y = config.sprites[config.sprites_order[i]].coords.y - config.pos.y;
	inv_det = 1.0 / (config.plane.x * config.dir.y -
					config.dir.x * config.plane.y);
	params->transform.x = inv_det * (-config.dir.y * sprite.x +
							config.dir.x * sprite.y);
	params->transform.y = inv_det * (-config.plane.y * sprite.x +
							config.plane.x * sprite.y);
	params->sprite_screen_x = (int)((config.res.w / 2) *
					(1 + params->transform.x / params->transform.y));
}

static t_sprite_params	calc_sprite(t_config config, int i)
{
	t_sprite_params	params;

	transform_coords(&params, config, i);
	params.height = abs((int)(config.res.h / params.transform.y));
	params.start_y = -params.height / 2 + config.res.h / 2;
	if (params.start_y < 0)
		params.start_y = 0;
	params.end_y = params.height / 2 + config.res.h / 2;
	if (params.end_y >= config.res.h)
		params.end_y = config.res.h - 1;
	params.width = abs((int)(config.res.h / params.transform.y));
	params.start_x = -params.width / 2 + params.sprite_screen_x;
	if (params.start_x < 0)
		params.start_x = 0;
	params.end_x = params.width / 2 + params.sprite_screen_x;
	if (params.end_x >= config.res.w)
		params.end_x = config.res.w - 1;
	return (params);
}

static void				render_line(int stripe, t_sprite_params params,
										t_vars *vars, t_frame *frame)
{
	int	tex_x;
	int	tex_y;
	int	d;
	int	color;
	int	y;

	tex_x = (int)(256 * (stripe - (-params.width / 2 +
	params.sprite_screen_x)) *
	vars->config.textures.sprite.width / params.width) / 256;
	if (params.transform.y > 0 && stripe > 0 &&
		stripe < vars->config.res.w &&
		params.transform.y < vars->z_buffer[stripe])
	{
		y = params.start_y;
		while (y < params.end_y)
		{
			d = y * 256 - vars->config.res.h * 128 + params.height * 128;
			tex_y = ((d * vars->config.textures.sprite.height) /
						params.height) / 256;
			color = get_pixel(vars->config.textures.sprite, tex_x, tex_y);
			if ((color & 0x00FFFFFF) != 0)
				pixel_put(frame, stripe, y, color);
			y++;
		}
	}
}

void					render_sprites(t_frame *frame, t_vars *vars)
{
	int				i;
	t_sprite_params	params;
	int				stripe;

	calc_dists(vars->config);
	sort_sprites(vars->config);
	i = 0;
	while (i < vars->config.sprites_count)
	{
		params = calc_sprite(vars->config, i);
		stripe = params.start_x;
		while (stripe < params.end_x)
		{
			render_line(stripe, params, vars, frame);
			stripe++;
		}
		i++;
	}
}
