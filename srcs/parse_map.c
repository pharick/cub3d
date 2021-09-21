/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:30:44 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/09 13:44:03 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

static int	check_map(char **map, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_strchr(" 120NWES", map[y][x]))
				return (1);
			if ((map[y][x] == '0' || map[y][x] == '2') && (
				y == 0 || y == height - 1 ||
				x == 0 || map[y][x + 1] == '\0' ||
				x >= (int)ft_strlen(map[y - 1]) || map[y - 1][x] == ' ' ||
				x >= (int)ft_strlen(map[y + 1]) || map[y + 1][x] == ' ' ||
				map[y][x - 1] == ' ' || map[y][x + 1] == ' '))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static void	set_dir_plane(t_config *config, int x, int y)
{
	config->dir.x = x;
	config->dir.y = y;
	config->plane.x = config->dir.x == 0 ? 0.66 * config->dir.y : 0;
	config->plane.y = config->dir.y == 0 ? -0.66 * config->dir.x : 0;
}

static int	set_pos(t_config *config, int x, int y)
{
	if (x == 0 || config->map[y][x + 1] == '\0' ||
		y == 0 || config->map[y + 1][x] == '\0' ||
		config->map[y][x + 1] == ' ' || config->map[y][x - 1] == ' ' ||
		config->map[y + 1][x] == ' ' || config->map[y - 1][x] == ' ')
		return (1);
	config->pos.x = x + 0.5;
	config->pos.y = y + 0.5;
	if (config->map[y][x] == 'N')
		set_dir_plane(config, 0, -1);
	else if (config->map[y][x] == 'S')
		set_dir_plane(config, 0, 1);
	else if (config->map[y][x] == 'W')
		set_dir_plane(config, -1, 0);
	else if (config->map[y][x] == 'E')
		set_dir_plane(config, 1, 0);
	return (0);
}

static int	find_player(t_config *config)
{
	int	y;
	int	x;
	int	player_set;

	player_set = 0;
	y = 0;
	while (y < config->map_height)
	{
		x = 0;
		while (config->map[y][x])
		{
			if (config->map[y][x] == 'N' || config->map[y][x] == 'S' ||
				config->map[y][x] == 'W' || config->map[y][x] == 'E')
			{
				if (player_set || set_pos(config, x, y))
					return (1);
				player_set = 1;
			}
			x++;
		}
		y++;
	}
	return (!player_set);
}

int			parse_map(t_config *config, char *line, int fd)
{
	t_list	*strs;

	strs = ft_lstnew(line);
	while (get_next_line(fd, &line) > 0)
	{
		ft_lstadd_back(&strs, ft_lstnew(line));
	}
	if (line[0] != '\0')
		ft_lstadd_back(&strs, ft_lstnew(line));
	else
		free(line);
	close(fd);
	config->map = (char**)ft_lst_to_array(strs);
	config->map_height = ft_lstsize(strs);
	ft_lstclear(&strs, NULL);
	if (check_map(config->map, config->map_height))
		return (1);
	if (find_player(config))
		return (1);
	parse_sprites(config);
	return (0);
}
