/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 12:33:22 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/06 16:22:51 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites.h"

static void	count_sprites(t_config *config)
{
	int	y;
	int	x;

	config->sprites_count = 0;
	y = 0;
	while (y < config->map_height)
	{
		x = 0;
		while (config->map[y][x])
		{
			if (config->map[y][x] == '2')
				config->sprites_count++;
			x++;
		}
		y++;
	}
}

void		parse_sprites(t_config *config)
{
	int	y;
	int	x;
	int	i;

	count_sprites(config);
	config->sprites = (t_sprite*)malloc(config->sprites_count *
							sizeof(t_sprite));
	config->sprites_order = (int*)malloc(config->sprites_count * sizeof(int));
	i = 0;
	y = 0;
	while (y < config->map_height)
	{
		x = 0;
		while (config->map[y][x])
		{
			if (config->map[y][x] == '2')
			{
				config->sprites[i].coords.x = x + 0.5;
				config->sprites[i].coords.y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

void		sort_sprites(t_config config)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < config.sprites_count - 1)
	{
		j = 0;
		while (j < config.sprites_count - i - 1)
		{
			if (config.sprites[config.sprites_order[j]].dist <
				config.sprites[config.sprites_order[j + 1]].dist)
			{
				tmp = config.sprites_order[j];
				config.sprites_order[j] = config.sprites_order[j + 1];
				config.sprites_order[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
