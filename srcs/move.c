/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:48:39 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/04 11:19:52 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

static void	move_x(t_config *config, double move_speed)
{
	if (config->map[(int)config->pos.y]
		[(int)(config->pos.x + config->dir.x * move_speed)] != '1')
		config->pos.x += config->dir.x * move_speed;
	if (config->map[(int)(config->pos.y + config->dir.y * move_speed)]
		[(int)config->pos.x] != '1')
		config->pos.y += config->dir.y * move_speed;
}

static void	move_y(t_config *config, double move_speed)
{
	if (config->map[(int)config->pos.y]
		[(int)(config->pos.x + config->plane.x * move_speed)] != '1')
		config->pos.x += config->plane.x * move_speed;
	if (config->map[(int)(config->pos.y + config->plane.y * move_speed)]
		[(int)config->pos.x] != '1')
		config->pos.y += config->plane.y * move_speed;
}

static void	rotate(t_config *config, double rotate_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = config->dir.x;
	config->dir.x = config->dir.x * cos(rotate_speed) -
					config->dir.y * sin(rotate_speed);
	config->dir.y = old_dir_x * sin(rotate_speed) +
					config->dir.y * cos(rotate_speed);
	old_plane_x = config->plane.x;
	config->plane.x = config->plane.x * cos(rotate_speed) -
						config->plane.y * sin(rotate_speed);
	config->plane.y = old_plane_x * sin(rotate_speed) +
						config->plane.y * cos(rotate_speed);
}

void		move_player(t_keys keys, t_config *config)
{
	if (keys.w)
		move_x(config, MOVE_SPEED);
	if (keys.s)
		move_x(config, -MOVE_SPEED);
	if (keys.d)
		move_y(config, -MOVE_SPEED);
	if (keys.a)
		move_y(config, MOVE_SPEED);
	if (keys.right)
		rotate(config, ROTATE_SPEED);
	if (keys.left)
		rotate(config, -ROTATE_SPEED);
}
