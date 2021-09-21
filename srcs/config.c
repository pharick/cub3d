/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 00:19:45 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/06 15:54:46 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static int	check_config(t_config *config)
{
	return (config->res.w <= 0 || config->res.h <= 0 ||
			!config->textures.north.img || !config->textures.south.img ||
			!config->textures.west.img || !config->textures.east.img ||
			!config->textures.sprite.img ||
			config->textures.floor < 0 || config->textures.ceil < 0);
}

static int	parse_color(t_vars *vars, char *color)
{
	char	**tokens;
	int		tokens_len;
	int		r;
	int		g;
	int		b;

	if (!(tokens = ft_split(color, ',')))
		clean_exit(vars, print_error(ERROR_MALLOC));
	tokens_len = ft_tokens_len(tokens);
	if (tokens_len != 3)
		return (-1);
	r = ft_atoi(tokens[0]);
	g = ft_atoi(tokens[1]);
	b = ft_atoi(tokens[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		clean_exit(vars, print_error(ERROR_CONFIG));
	ft_free_tokens(tokens, tokens_len);
	return (0 << 24 | r << 16 | g << 8 | b);
}

static void	set_res(t_vars *vars, int w, int h)
{
	int	display_w;
	int	display_h;

	mlx_get_screen_size(vars->mlx, &display_w, &display_h);
	vars->config.res.w = display_w < w ? display_w : w;
	vars->config.res.h = display_h < h ? display_h : h;
}

static void	parse_element(t_vars *vars, char *line)
{
	char	**tokens;
	int		tokens_len;

	if (!(tokens = ft_split(line, ' ')))
		clean_exit(vars, print_error(ERROR_MALLOC));
	tokens_len = ft_tokens_len(tokens);
	if (!ft_strcmp(tokens[0], "R") && tokens_len == 3)
		set_res(vars, ft_atoi(tokens[1]), ft_atoi(tokens[2]));
	else if (!ft_strcmp(tokens[0], "NO") && tokens_len == 2)
		vars->config.textures.north = load_xpm_texture(vars->mlx, tokens[1]);
	else if (!ft_strcmp(tokens[0], "SO") && tokens_len == 2)
		vars->config.textures.south = load_xpm_texture(vars->mlx, tokens[1]);
	else if (!ft_strcmp(tokens[0], "WE") && tokens_len == 2)
		vars->config.textures.west = load_xpm_texture(vars->mlx, tokens[1]);
	else if (!ft_strcmp(tokens[0], "EA") && tokens_len == 2)
		vars->config.textures.east = load_xpm_texture(vars->mlx, tokens[1]);
	else if (!ft_strcmp(tokens[0], "S") && tokens_len == 2)
		vars->config.textures.sprite = load_xpm_texture(vars->mlx, tokens[1]);
	else if (!ft_strcmp(tokens[0], "F") && tokens_len == 2)
		vars->config.textures.floor = parse_color(vars, tokens[1]);
	else if (!ft_strcmp(tokens[0], "C") && tokens_len == 2)
		vars->config.textures.ceil = parse_color(vars, tokens[1]);
	ft_free_tokens(tokens, tokens_len);
}

int			config_load(t_vars *vars, char *path)
{
	int		fd;
	char	*line;

	line = NULL;
	if ((fd = open(path, O_RDONLY)) < 0)
		clean_exit(vars, print_error(ERROR_CONFIG));
	while (get_next_line(fd, &line) > 0 &&
			(ft_strlen(line) == 0 || !ft_strchr(" 01", *line)))
	{
		if (ft_strlen(line) == 0)
		{
			free(line);
			continue;
		}
		parse_element(vars, line);
		free(line);
	}
	if (check_config(&vars->config))
	{
		close(fd);
		clean_exit(vars, print_error(ERROR_CONFIG));
	}
	if (parse_map(&vars->config, line, fd))
		clean_exit(vars, print_error(ERROR_CONFIG));
	return (0);
}
