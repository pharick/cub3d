/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:21:40 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/06 16:09:04 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "config.h"
#include "render.h"
#include "keys.h"
#include "clean.h"
#include "bitmap.h"
#include "errors.h"

static void	init_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->window = NULL;
	vars->frame.img = NULL;
	vars->buffer.img = NULL;
	vars->config.textures.north.img = NULL;
	vars->config.textures.south.img = NULL;
	vars->config.textures.east.img = NULL;
	vars->config.textures.west.img = NULL;
	vars->config.textures.sprite.img = NULL;
	vars->config.map = NULL;
	vars->config.sprites = NULL;
	vars->config.sprites_order = NULL;
	vars->z_buffer = NULL;
	vars->z_buffer = NULL;
	vars->config.res.w = 0;
	vars->config.res.h = 0;
	vars->config.textures.floor = -1;
	vars->config.textures.ceil = -1;
}

static void	init(t_vars *vars, char *path)
{
	if (!(vars->mlx = mlx_init()))
		clean_exit(vars, print_error(ERROR_MLX_INIT));
	config_load(vars, path);
	if (!(vars->window = mlx_new_window(vars->mlx, vars->config.res.w,
									vars->config.res.h, "cub3d")))
		clean_exit(vars, print_error(ERROR_WINDOW));
	if (!(vars->frame.img = mlx_new_image(vars->mlx, vars->config.res.w,
								vars->config.res.h)))
		clean_exit(vars, print_error(ERROR_IMG));
	vars->frame.addr = mlx_get_data_addr(vars->frame.img,
	&vars->frame.bits_per_pixel, &vars->frame.size_line, &vars->frame.endian);
	if (!(vars->buffer.img = mlx_new_image(vars->mlx, vars->config.res.w,
								vars->config.res.h)))
		clean_exit(vars, print_error(ERROR_IMG));
	vars->buffer.addr = mlx_get_data_addr(vars->buffer.img,
	&vars->buffer.bits_per_pixel, &vars->buffer.size_line,
	&vars->buffer.endian);
	if (!(vars->z_buffer = (double*)malloc(vars->config.res.w *
		sizeof(double))))
		clean_exit(vars, print_error(ERROR_MALLOC));
}

int			main(int argc, char **argv)
{
	t_vars	vars;

	init_vars(&vars);
	if (argc < 2 || argc > 3 || (argc == 3 && ft_strcmp(argv[2], "--save")))
		clean_exit(&vars, print_error(ERROR_ARGS));
	init(&vars, argv[1]);
	if (argc == 3 && !ft_strcmp(argv[2], "--save"))
	{
		render(&vars);
		save_bitmap(&vars);
		clean_exit(&vars, 0);
	}
	init_keys(&vars.keys);
	mlx_do_key_autorepeatoff(vars.mlx);
	mlx_hook(vars.window, 2, 1L << 0, handle_keypress, &vars);
	mlx_hook(vars.window, 3, 1L << 1, handle_keyrelease, &vars);
	mlx_hook(vars.window, 17, 1L << 0, handle_exit, &vars);
	mlx_loop_hook(vars.mlx, next_frame, &vars);
	mlx_loop(vars.mlx);
}
