/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:06:16 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/04 11:19:14 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"

static t_vector	get_delta_dist(t_vector ray_dir)
{
	t_vector	delta_dist;

	if (ray_dir.y == 0)
		delta_dist.x = 0;
	else if (ray_dir.x == 0)
		delta_dist.x = 1;
	else
		delta_dist.x = fabs(1 / ray_dir.x);
	if (ray_dir.x == 0)
		delta_dist.y = 0;
	else if (ray_dir.y == 0)
		delta_dist.y = 1;
	else
		delta_dist.y = fabs(1 / ray_dir.y);
	return (delta_dist);
}

static t_vector	get_step(t_vector *side_dist, t_config config,
							t_vector ray_dir, t_vector delta_dist)
{
	t_vector	step;

	if (ray_dir.x < 0)
	{
		step.x = -1;
		side_dist->x = (config.pos.x - (int)config.pos.x) * delta_dist.x;
	}
	else
	{
		step.x = 1;
		side_dist->x = ((int)config.pos.x + 1 - config.pos.x) * delta_dist.x;
	}
	if (ray_dir.y < 0)
	{
		step.y = -1;
		side_dist->y = (config.pos.y - (int)config.pos.y) * delta_dist.y;
	}
	else
	{
		step.y = 1;
		side_dist->y = ((int)config.pos.y + 1 - config.pos.y) * delta_dist.y;
	}
	return (step);
}

static t_dda	make_step(t_vector *side_dist, t_vector *map_pos,
							t_vector delta_dist, t_vector step)
{
	t_dda	result;

	if (side_dist->x < side_dist->y)
	{
		side_dist->x += delta_dist.x;
		map_pos->x += step.x;
		result.side = step.x > 0 ? WEST_WALL : EAST_WALL;
	}
	else
	{
		side_dist->y += delta_dist.y;
		map_pos->y += step.y;
		result.side = step.y > 0 ? NORTH_WALL : SOUTH_WALL;
	}
	return (result);
}

static t_dda	throw_ray(t_config config, t_vector delta_dist,
							t_vector ray_dir)
{
	t_vector	side_dist;
	t_vector	step;
	t_vector	map_pos;
	t_dda		result;
	int			hit;

	map_pos.x = (int)config.pos.x;
	map_pos.y = (int)config.pos.y;
	step = get_step(&side_dist, config, ray_dir, delta_dist);
	hit = 0;
	while (!hit)
	{
		result = make_step(&side_dist, &map_pos, delta_dist, step);
		if (config.map[(int)map_pos.y][(int)map_pos.x] == '1')
			hit = 1;
	}
	if (result.side == EAST_WALL || result.side == WEST_WALL)
		result.wall_dist = (map_pos.x - config.pos.x +
								(1 - step.x) / 2) / ray_dir.x;
	else
		result.wall_dist = (map_pos.y - config.pos.y +
								(1 - step.y) / 2) / ray_dir.y;
	return (result);
}

t_dda			dda(t_config config, t_vector ray_dir)
{
	t_vector	delta_dist;
	t_dda		result;

	delta_dist = get_delta_dist(ray_dir);
	result = throw_ray(config, delta_dist, ray_dir);
	return (result);
}
